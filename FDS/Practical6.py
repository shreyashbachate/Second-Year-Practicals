class QuickSort:
    
    def quicksort(self,arr, lpart, rpart):
        if lpart < rpart:
            temp = self.parts(arr, lpart, rpart)
            if temp==len(arr)-1 and lpart==0:
                print("Array already sorted")
            else:
                self.quicksort(arr, lpart, temp - 1)
                self.quicksort(arr, temp + 1, rpart)
        

    def parts(self,arr, lpart, rpart):
        flag=0
        i = (lpart - 1)
        pivot = arr[rpart]
        for j in range(lpart, rpart):
            if arr[j] <= pivot:
                i = i + 1
                arr[i], arr[j] = arr[j], arr[i]

        arr[i + 1], arr[rpart] = arr[rpart], arr[i + 1]
          
        print("Iteration :",arr)
        return (i + 1)



    def check(self,temp):
        if temp > 100.0:
            temp = float(input("Enter Percentage Less Than 100 : "))
            self.check(temp)
            return temp
        elif temp < 0.0:
            temp = float(input("Enter Percentage Greater Than 0 : "))
            self.check(temp)
            return temp
        elif temp == -0.0:
            temp = float(input("Enter proper input : "))
            self.check(temp)
            return temp

        else:
            return temp
        self.choice()

    def choice(self):
        print("Do You Want To Continue Your Execution.. Type y/n ")
        ch = input()[0]
        while True:
            if ch == 'y':
                self.menu()
            elif ch == 'n':
                print("Terminated....")
                break
            else:
                print("Incorrect Entry.... Terminating the Program.....")
                break
    def menu(self):
        arr = []
        no = int(input("Enter Number Of Students :"))
        if no >= 5:
            print("Enter Percentage of Students :")
            while True:
                try:
                    temp = float(input())
                    temp = self.check(temp)
                    arr.append(temp)
                except Exception as e:
                    print("Exception Caught : {0}", format(e))
                    print("Enter Proper Float :")
                if len(arr)==no:
                    break 

            print("ALL PERCENTAGES ARE: ", arr)
            self.quicksort(arr, 0, no - 1)
            lst1 = arr
            lst1 = lst1[::-1]
            print("TOP 5 PERCENTAGES ARE :", lst1[0:5])
            self.choice()
        else:
            print("Enter Record Of More than or Equal to 5 Students")
            self.menu()

s=QuickSort()
s.menu()