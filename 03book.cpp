#include <iostream>
#include <string.h>
using namespace std;
struct node
{
    /* data */
    char name[20];
    node *next;
    node *down;
    int flag;
};

class gll
{
    char ch[20];
    int n, i;
    node *head = NULL, *temp = NULL, *t1 = NULL, *t2 = NULL;

public:
    node *create();
    void insertb();
    void insertc();
    void inserts();
    void insertss();
    void displayb();
};

node *gll::create()
{
    node *p = new node;
    p->next = NULL;
    p->down = NULL;
    p->flag = 0;
    cout << "\n enter the name";
    cin >> p->name;
    return p;
}
void gll::insertb()
{
    if (head == NULL)
    {
        t1 = create();
        head = t1;
    }
    else
    {
        cout << "bookexits";
    }
}

void gll::insertc()
{
    if (head == NULL)
    {
        cout << "No BOOK";
    }
    else
    {
        cout << "Enter no of chapters:";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            t1 = create();
            if (head->flag == 0)
            {
                head->down = t1;
                head->flag = 1;
            }
            else
            {
                temp = head;
                temp = temp->down;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = t1;
            }
        }
    }
}

void gll::inserts()
{
    if (head == NULL)
    {
        cout << "there is no nbook";
    }
    else
    {
        cout << "enter thename iof chapter on whucb you have to enetr subsection";
        cin >> ch;
        temp = head;
        if (temp->flag == 0)
        {
            cout << "their are no chapteres";
        }
        else
        {
            temp = temp->down;
            while (temp != NULL)
            {
                if (!strcmp(ch, temp->name))
                {
                    cout << "how many sections you want ot insert: ";
                    cin >> n;
                    for (i = 0; i < n; i++)
                    {
                        t1 = create();
                        if (temp->flag == 0)
                        {
                            temp->down = t1;
                            temp->flag = 1;
                            t2 = temp->down;
                        }
                        else
                        {
                            cout << "\n#####";
                            while (t2->next != NULL)
                            {
                                t2 = t2->next;
                            }
                            t2->next = t1;
                        }
                    }
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void gll::insertss()
{
    if (head == NULL)
    {
        cout << "\n There is no book.";
    }
    else
    {
        cout << "\n Enter the name of the chapter in which you want to enter the section: ";
        cin >> ch;

        temp = head->down; // Start with the first chapter

        while (temp != NULL)
        {
            if (!strcmp(ch, temp->name))
            {
                cout << "\n Enter the name of the section in which you want to enter the subsection: ";
                cin >> ch;

                if (temp->flag == 0)
                {
                    cout << "\n There are no sections.";
                }
                else
                {
                    node *tempSection = temp->down; // Start with the first section
                    while (tempSection != NULL)
                    {
                        if (strcmp(ch, tempSection->name) == 0)
                        {
                            cout << "\n How many subsections do you want to enter? ";
                            cin >> n;
                            for (i = 0; i < n; i++)
                            {
                                t1 = create();
                                if (tempSection->flag == 0)
                                {
                                    tempSection->down = t1;
                                    tempSection->flag = 1;
                                    t2 = tempSection->down;
                                }
                                else
                                {
                                    while (t2->next != NULL)
                                    {
                                        t2 = t2->next;
                                    }
                                    t2->next = t1;
                                }
                            }
                            break;
                        }
                        tempSection = tempSection->next;
                    }
                    if (tempSection == NULL)
                    {
                        cout << "\n The specified section was not found.";
                    }
                }
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "\n The specified chapter was not found.";
        }
    }
}

void gll::displayb()
{
    if (head == NULL)
    {
        cout << "book not exist";
    }
    else
    {
        temp = head;
        cout << "name of book:" << temp->name;
        if (temp->flag == 1)
        {
            temp = temp->down;
            while (temp != NULL)
            {
                cout << "name of chapter:" << temp->name;
                t1 = temp;
                if (t1->flag == 1)
                {
                    t1 = t1->down;
                    while (t1 != NULL)

                    {
                        cout << "Nmae oif section" << t1->name;
                        t2 = t1;
                        if (t2->flag == 1)
                        {
                            t2 = t2->down;
                            while (t2 != NULL)
                            {
                                cout << "name of subsection" << t2->name;
                                t2 = t2->next;
                            }
                        }
                        t1 = t1->next;
                    }
                }
                temp = temp->next;
            }
        }
    }
}

int main()
{
    gll g;
    int x;
    while (1)
    {
        cout << "\n\n enter your choice";
        cout << "\n 1.insert book";
        cout << "\n 2.insert chapter";
        cout << "\n 3.insert section";
        cout << "\n 4.insert subsection";
        cout << "\n 5.display book";
        cout << "\n 6.exit";
        cin >> x;
        switch (x)
        {
        case 1:
            g.insertb();
            break;
        case 2:
            g.insertc();
            break;
        case 3:
            g.inserts();
            break;
        case 4:
            g.insertss();
            break;
        case 5:
            g.displayb();
            break;
        case 6:
            exit(0);
        }
    }
}
