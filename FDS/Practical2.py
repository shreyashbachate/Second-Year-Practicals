class STROP:
    def lword(self,word):
        lst = word.split()
        ll = lst[0]
        for i in lst:
            if len(i) > len(ll):
                ll = i
        print("word with longest length is :", ll)
        self.choice()

    def freq(self,str, ch):
        cnt = 0
        for i in str:
            if i == ch:
                cnt = cnt + 1
        print("Frequency of character", ch, "is", cnt)
        self.choice()

    def palindrome(self,str):
        if str == str[::-1]:
            print("Palindrome ")
        else:
            print("Not Plaindrome")
        self.choice()

    def fapp(self,str, wrd):
        ind = 0
        for i in range(len(str) - len(wrd) + 1):
            if wrd == str[i:i + len(wrd)]:
                ind = i
        print("Index is:", ind)
        self.choice()

    def wrdcnt(self,str):
        str = str.split()         
        str2 = []
        for i in str:             
            if i not in str2:
                str2.append(i)         
        for i in range(0, len(str2)):
            print('Frequency of', str2[i], ':', str.count(str2[i]))
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
        print("Select Yor Choice:")
        print("1.To display word with longest length")
        print("2.To determine frequency of occurance of particular character in the string")
        print("3.To check whether the string is palindrome or not")
        print("4.To display index of first apperance of substring")
        print("5.To count the occurance of word in string")
        ch = int(input("Enter Your Choice : "))
        if ch == 1:
            str = input("Enter the string : ")
            self.lword(str)
        elif ch == 2:
            str = input("Enter the string : ")
            ch = input("Enter the chracter : ")
            self.freq(str, ch)
        elif ch == 3:
            str = input("Enter the string : ")
            self.palindrome(str)
        elif ch == 4:
            str = input("Enter the string : ")
            str1 = input("Enter the sub-string : ")
            self.fapp(str, str1)
        elif ch == 5:
            str = input("Enter the string : ")
            self.wrdcnt(str)
s=STROP()
s.menu()