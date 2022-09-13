class Sport:
    def ch1(self,cricket, badminton):
        lst = []
        for i in cricket:
            if i in badminton:
                lst.append(i)
        print("Cricket:", cricket)
        print("Badminton:", badminton)
        print("List of students who play both cricket and badminton: ", lst)



    def ch2(self,cricket, badminton):
            lst = []
            for i in cricket:
                if i not in badminton:
                    lst.append(i)
            for i in badminton:
                if i not in cricket:
                    lst.append(i)
            print("Cricket:", cricket)
            print("Badminton:", badminton)
            print("List of students who play either cricket or badminton but not both: ", lst)



    def ch3(self,cricket, football, badminton):
        lst = cricket + badminton
        lst1 = []
        for i in football:
            if i not in lst:
                lst1.append(i)
        print("Cricket:", cricket)
        print("Football:", football)
        print("Badminton:", badminton)
        print("Students who play neither cricket nor badminton are: ", lst1)





    def ch4(self ,cricket, football, badminton):
        lst1 = cricket + football
        lst=[]
        for i in lst1:
            if i not in badminton:
                if i not in lst:
                    lst.append(i)
        print("Cricket:", cricket)
        print("Football:", football)
        print("Badminton:", badminton)
        print("Students who play cricket and football but noit badminton: ", lst)



    def check(self, arr, ele):
        if ele in arr:
            print("Enter Input Other Than ", arr)
            player = int(input())
            if player not in arr:
                return player
        else:
            return ele





    def menu( self):
        cricket = []
        badminton = []
        football = []

        print("Enter number of students playing cricket: ")
        num = int(input())
        for i in range(num):
            player = input("Enter cricket playing students: ")
            player = self.check(cricket, player)
            cricket.append(player)
        print(cricket)

        print("Enter number of students playing badminton: ")
        num1 = int(input())
        for i in range(num1):
            player = input("Enter badminton playing students: ")
            player = self.check(badminton, player)
            badminton.append(player)
        print(badminton)

        print("Enter number of students playing football: ")
        num2 = int(input())
        for i in range(num2):
            player = input("Enter football playing students: ")
            player = self.check(football, player)
            football.append(player)
        print(football)
        
        while True:
            print("------------------------------------------------------------------------------")
            print("Select Yor Choice:")
            print("1.List of students who play both cricket and badminton")
            print("2.List of students who play either cricket or badminton but not both")
            print("3.Students who play neither cricket nor badminton")
            print("4.Students who play cricket and football but noit badminton")
            print("5.Exit")
            ch = int(input("Enter Your Choice : "))
            if ch == 1:
                self.ch1(cricket, badminton)
            elif ch == 2:
                self.ch2(cricket, badminton)
            elif ch == 3:
                self.ch3(cricket, football, badminton)
            elif ch == 4:
                self.ch4(cricket, football, badminton)
            elif ch == 5:
                print("Terminated.....")
                break

s=Sport()
s.menu()