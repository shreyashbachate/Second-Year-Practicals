class Sort:
    def insertionsort(self,arr):
        flag=0
        for i in range(1, len(arr)):
            temp = arr[i]
            j = i - 1
            while j >= 0 and temp < arr[j]:
                flag=1
                arr[j + 1] = arr[j]
                j = j - 1
                arr[j + 1] = temp
            if flag==0:
                print("Array already sorted")
                break
            print("Iteartion ",i,": ",arr)
        print("ALL PERCENTAGES ARE:", arr)
        arr = arr[::-1]
        print("\n TOP 5 PERCENTAGE IS : ", arr[:5])
        self.choice()

    def shellsort(self,arr):
        flag=0
        n = len(arr)
        gap = int(n / 2)
        while gap > 0:
            for i in range(gap, n):
                temp = arr[i]
                j = i
                while j >= gap and arr[j - gap] > temp:
                    flag=1
                    arr[j] = arr[j - gap]
                    j = j - gap
                arr[j] = temp
            if flag==0:
                print("Array already sorted")
                break
            print("Iteration :",arr)
            gap = int(gap / 2)
        print("ALL PERCENTAGES ARE:", arr)
        arr = arr[::-1]
        print("\nTOP 5 PERCENTAGE IS: ", arr[:5:])
        self.choice()

    def check(self,temp):
        if temp > 100:
            temp = float(input("Enter Percentage Less Than 100 :"))
            self.check(temp)
            return temp
        elif temp < 0:
            temp = float(input("Enter Percentage Greater  Than 0 :"))
            self.check(temp)
            return temp
        else:
            return temp

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
        no = int(input("Enter Number Of Students : "))
        if no >= 5:
            print("Enter Percentage of Students : ")
            for i in range(no):
                try:
                    temp = float(input())
                    temp = self.check(temp)
                    arr.append(temp)
                except Exception as e:
                    print("Exception Caught : {0}", format(e))
                    print("Enter Proper Float")

            print("-----Select Choice------")
            print("1.Sort Using Insertion Sort")
            print("2. Sort Using Shell Sort")
            ch = int(input())
            if ch == 1:
                self.insertionsort(arr)
            elif ch == 2:
                self.shellsort(arr)
            else:
                print("Incorrect Choice, Plz Input Between 1 and 2 :")
                self.menu()
        else:
            print("Enter Record Of More than or Equal to 5 Students :")
            self.menu()

s=Sort()
s.menu()