class Search:
    def linsearch(self,lst, rn):
        for i in lst:
            if i == rn:
                print("Student ", rn, " Attended The Training")
                break

        else:
            print("Student", rn, " Was Absent")
        self.choice()

    def sensearch(self,lst, rn):
        temp = lst[-1]
        lst[-1] = rn
        i = 0
        while (lst[i] != rn):
            i = i + 1
        lst[-1] = temp
        if i != len(lst):
            print("Student", rn, " Attended The Training")
        else:
            print("Student", rn, " Was Absent")
        self.choice()

    # def sorting(self,lst):
    #     lst1 = []
    #     min = lst[0]
    #     for j in range(len(lst)):
    #         for i in range(j + 1, len(lst)):
    #             if lst[j] > lst[i]:
    #                 temp = lst[j]
    #                 lst[j] = lst[i]
    #                 lst[i] = temp

    #     return lst

    def binsearch(self,lst, rn):
        start = 0
        end = len(lst) - 1
        mid = (start + end) // 2
        while start <= end:
            mid = (start + end) // 2
            if lst[mid] < rn:
                start = mid + 1
            elif lst[mid]> rn:
                end = mid - 1
            else:
                return rn

    def fibonaci(self,lst,rn):

        size = len(lst)

        start = -1
        flag = False
        f0 = 0
        f1 = 1
        f2 = 1
        while (f2 < size):
            f0 = f1
            f1 = f2
            f2 = f1 + f0

        while (f2 > 1):
            index = min(start + f0, size - 1)
            if lst[index] < rn:
                f2 = f1
                f1 = f0
                f0 = f2 - f1
                start = index

            elif lst[index] == rn:
                print("Student", rn, " Attended the Program")
                flag = True
                break
            else:
                f2 = f0
                f1 = f1 - f0
                f0 = f2 - f1
        if (flag == False):
            print("Student", rn, " was absent..")

        self.choice()

    def choice(self):
        print("Do You Want To Continue Your Execution.. Type y/n ")
        ch = input()[0]
        if ch == 'y':
            self.menu()
        elif 'n' == ch:
            print("Terminated....")
        else:
            print("Incorrect Entry.... Terminating the Program.....")

    def menu(self):
        arr = []
        arr = self.data(arr)
        print("Enter Roll Number TO Search")
        rn = int(input())
        print("Select Searching Technique\n")
        print("1.Linear Search \n 2.Sentinel Search \n 3.Fibonacci Search \n 4.Binary Search ")
        ch = int(input("Enter Your Choice"))
        if ch == 1:
            self.linsearch(arr, rn)
        if ch == 2:
            self.sensearch(arr, rn)
        if ch == 3:
            # arr=self.sorting(arr)
            rn = self.fibonaci(arr, rn)
            print(rn)
        if ch == 4:
            # arr=self.sorting(arr)
            rn = self.binsearch(arr, rn)
            print(rn, "was Present")
            self.choice()

    def check(self,arr, ele):
        if ele in arr:
            print("Enter Input Other Than ", arr)
            ele = int(input())
            if ele not in arr:
                return ele
        else:
            return ele

    def data(self,arr):

        print("Enter Number Of Student Attended the Training")
        no = int(input())
        print("Enter Roll Number Of Students")
        for i in range(no):
            try:
                temp = int(input())
                temp = self.check(arr, temp)
                arr.append(temp)
            except Exception as e :
                print("Exception Caught : {0}",format(e))
                print("Enter Proper Integer")

        return arr

s=Search()
s.menu()