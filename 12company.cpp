#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <limits>
using namespace std;

const string fileName = "Employee.txt";

class Employee
{
private:
    int EmpID;
    string EmpName, Post, Department;
    float Salary;

public:
    void ReadData();
    int GetID() const;
    void DisplayRecord() const;
    const string &GetDepartment() const;

    // Serialization functions
    friend ostream &operator<<(ostream &os, const Employee &employee);
    friend istream &operator>>(istream &is, Employee &employee);
};

void Employee::ReadData()
{
    cout << "Employee ID: ";
    cin >> EmpID;
    cout << "Employee Name: ";
    cin >> EmpName;
    cout << "Employee's Post: ";
    cin >> Post;
    cout << "Employee's Department: ";
    cin >> Department;
    cout << "Salary: ";
    cin >> Salary;
}

void Employee::DisplayRecord() const
{
    cout << "_______________________________" << endl;
    cout << left << setw(5) << EmpID << setw(15) << EmpName << setw(15)
         << Post << setw(15) << Department << setw(8) << Salary << endl;
}

int Employee::GetID() const
{
    return EmpID;
}

const string &Employee::GetDepartment() const
{
    return Department;
}

// Serialization functions

ostream &operator<<(ostream &os, const Employee &employee)
{
    os << employee.EmpID << '\n'
       << employee.EmpName << '\n'
       << employee.Post << '\n'
       << employee.Department << '\n'
       << employee.Salary << '\n';
    return os;
}

istream &operator>>(istream &is, Employee &employee)
{
    is >> employee.EmpID;
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(is, employee.EmpName);
    getline(is, employee.Post);
    getline(is, employee.Department);
    is >> employee.Salary;
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    return is;
}

// Function to load employees from the file
vector<Employee> LoadEmployeesFromFile()
{
    vector<Employee> employees;
    ifstream file(fileName);
    if (file)
    {
        Employee employee;
        while (file >> employee)
        {
            employees.push_back(employee);
        }
        file.close();
    }
    return employees;
}

// Function to save employees to the file
void SaveEmployeesToFile(const vector<Employee> &employees)
{
    ofstream file(fileName);
    if (file)
    {
        for (const auto &employee : employees)
        {
            file << employee;
        }
        file.close();
    }
}

int main()
{
    vector<Employee> employees = LoadEmployeesFromFile();

    while (true)
    {
        cout << "*******Menu********" << endl;
        cout << "Enter your option" << endl;
        cout << "1 => Add a new record" << endl;
        cout << "2 => Search record from employee id" << endl;
        cout << "3 => List Employee of particular department" << endl;
        cout << "4 => Display all employees" << endl;
        cout << "5 => Update record of an employee" << endl;
        cout << "6 => Delete record of particular employee" << endl;
        cout << "7 => Exit from the program" << endl;
        cout << "********************" << endl;

        char option;
        cin >> option;

        if (option == '1')
        {
            Employee emp;
            emp.ReadData();

            auto it = find_if(employees.begin(), employees.end(),
                              [&emp](const Employee &e)
                              { return e.GetID() == emp.GetID(); });

            if (it != employees.end())
            {
                cout << "This ID already exists. Try another ID." << endl;
            }
            else
            {
                employees.push_back(emp);
                cout << "New record has been added successfully..." << endl;
            }
        }
        else if (option == '2')
        {
            int ID;
            cout << "Enter ID of an employee to be searched: ";
            cin >> ID;

            auto it = find_if(employees.begin(), employees.end(),
                              [ID](const Employee &e)
                              { return e.GetID() == ID; });

            if (it != employees.end())
            {
                cout << "The record found...." << endl;
                cout << "ID      Name           Post           Department     Salary" << endl;
                it->DisplayRecord();
            }
            else
            {
                cout << "Data not found for employee ID#" << ID << endl;
            }
        }
        else if (option == '3')
        {
            string Dept;
            cout << "Enter department name to list employees within it: ";
            cin >> Dept;

            bool found = false;
            for (const auto &emp : employees)
            {
                if (emp.GetDepartment() == Dept)
                {
                    if (!found)
                    {
                        cout << "The record found for this department" << endl;
                        cout << "ID      Name           Post           Department     Salary" << endl;
                        found = true;
                    }
                    emp.DisplayRecord();
                }
            }

            if (!found)
            {
                cout << "Data not found for department " << Dept << endl;
            }
        }
        else if (option == '4')
        {
            if (employees.empty())
            {
                cout << "No records found." << endl;
            }
            else
            {
                cout << "ID      Name           Post           Department     Salary" << endl;
                for (const auto &emp : employees)
                {
                    emp.DisplayRecord();
                }
            }
        }
        else if (option == '7')
        {
            SaveEmployeesToFile(employees);
            return 0;
        }
        else
        {
            cout << "Invalid option" << endl;
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> option;

        if (option == 'n' || option == 'N')
        {
            SaveEmployeesToFile(employees);
            break;
        }
    }

    return 0;
}
