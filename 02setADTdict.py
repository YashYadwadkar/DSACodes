class HashFunction:
    def __init__(self):
        self.h = [{'key': -1, 'name': 'NULL'} for _ in range(10)]

    def insert(self):
        cnt = 0
        flag = 0
        while True:
            if cnt >= 10:
                print("\n\tHash Table is FULL")
                break
            k = int(input("\n\tEnter a Telephone No: "))
            n = input("\n\tEnter a Client Name: ")
            hi = k % 10  # hash function
            if self.h[hi]['key'] == -1:
                self.h[hi]['key'] = k
                self.h[hi]['name'] = n
            else:
                if self.h[hi]['key'] % 10 != hi:
                    temp = self.h[hi]['key']
                    ntemp = self.h[hi]['name']
                    self.h[hi]['key'] = k
                    self.h[hi]['name'] = n
                    for i in range(hi + 1, 10):
                        if self.h[i]['key'] == -1:
                            self.h[i]['key'] = temp
                            self.h[i]['name'] = ntemp
                            flag = 1
                            break
                    for i in range(hi):
                        if flag == 0 and self.h[i]['key'] == -1:
                            self.h[i]['key'] = temp
                            self.h[i]['name'] = ntemp
                            break
                else:
                    for i in range(hi + 1, 10):
                        if self.h[i]['key'] == -1:
                            self.h[i]['key'] = k
                            self.h[i]['name'] = n
                            flag = 1
                            break
                    for i in range(hi):
                        if flag == 0 and self.h[i]['key'] == -1:
                            self.h[i]['key'] = k
                            self.h[i]['name'] = n
                            break
            flag = 0
            cnt += 1
            ans = input("\n\t..... Do You Want to Insert More Key: y/n: ")
            if ans != 'y' and ans != 'Y':
                break

    def display(self):
        print("\n\t\tKey\t\tName")
        for i in range(10):
            print("\n\th[{}]\t{}\t\t{}".format(
                i, self.h[i]['key'], self.h[i]['name']))

    def find(self, k):
        for i in range(10):
            if self.h[i]['key'] == k:
                print("\n\t{} is Found at {} Location With Name {}".format(
                    self.h[i]['key'], i, self.h[i]['name']))
                return i
        print("\n\tKey Not Found")
        return -1

    def delete(self, k):
        index = self.find(k)
        if index != -1:
            self.h[index]['key'] = -1
            self.h[index]['name'] = "NULL"
            print("\n\tKey is Deleted")


if __name__ == '__main__':
    obj = HashFunction()
    while True:
        print("\n\t***** Telephone (ADT) *****")
        print("\n\t1. Insert\n\t2. Display\n\t3. Find\n\t4. Delete\n\t5. Exit")
        ch = int(input("\n\t..... Enter Your Choice: "))
        if ch == 1:
            obj.insert()
        elif ch == 2:
            obj.display()
        elif ch == 3:
            k = int(input("\n\tEnter a Key Which You Want to Search: "))
            obj.find(k)
        elif ch == 4:
            k = int(input("\n\tEnter a Key Which You Want to Delete: "))
            obj.delete(k)
        elif ch == 5:
            break
        ans = input("\n\t..... Do You Want to Continue in Main Menu: y/n: ")
        if ans != 'y' and ans != 'Y':
            break
