class Matrix:
    def add(self):
        row1 = int(input("Enter the Number of rows : "))
        column1 = int(input("Enter the Number of Columns: "))

        print("Enter the elements of First Matrix:")
        mat1 = [[int(input()) for i in range(column1)] for i in range(row1)]
        print("First Matrix is: ")
        for n in mat1:
            print(n)

        row2 = int(input("Enter the Number of rows : "))
        column2 = int(input("Enter the Number of Columns: "))

        if row1==row2 and column1==column2:
            print("Enter the elements of Second Matrix:")
            mat2 = [[int(input()) for i in range(column2)] for i in range(row2)]
            print("First Matrix is: ")
            for n in mat1:
                print(n)
            print("************")
            print("Second Matrix is: ")
            for n in mat2:
                print(n)

            res = [[0 for i in range(column1)] for i in range(row1)]

            for i in range(row1):
                for j in range(column1):
                    res[i][j] = mat1[i][j] + mat2[i][j]

            print("The Sum of Above two Matrices is : ")

            for r in res:
                print(r)
        
        else:
            print("Addition is not possible")
        self.choice()

    def sub(self):
        row1 = int(input("Enter the Number of rows : "))
        column1 = int(input("Enter the Number of Columns: "))

        print("Enter the elements of First Matrix:")
        mat1 = [[int(input()) for i in range(column1)] for i in range(row1)]
        print("First Matrix is: ")
        for n in mat1:
            print(n)

        row2 = int(input("Enter the Number of rows : "))
        column2 = int(input("Enter the Number of Columns: "))

        if row1==row2 and column1==column2:
            print("Enter the elements of Second Matrix:")
            mat2 = [[int(input()) for i in range(column2)] for i in range(row2)]
            print("First Matrix is: ")
            for n in mat1:
                print(n)
            print("************")
            print("Second Matrix is: ")
            for n in mat2:
                print(n)

            res = [[0 for i in range(column1)] for i in range(row1)]

            for i in range(row1):
                for j in range(column1):
                    res[i][j] = mat1[i][j] - mat2[i][j]

            print("The Subtraction of Above two Matrices is :" )

            for r in res:
                print(r)
        
        else:
            print("Subtraction is not possible")
        self.choice()

    def mul(self):
        rows_a = int(input("Enter the Number of rows  for the first matrix: "))
        column_a = int(input("Enter the Number of Columns for the first matrix: "))
        rows_b = int(input("Enter the Number of rows  for the second matrix: "))
        column_b = int(input("Enter the Number of Columns for the second matrix: "))
        if column_a == rows_b:
            print("Enter the elements of First Matrix:")
            mat1 = [[int(input()) for i in range(column_a)] for i in range(rows_a)]

            print("First Matrix is: ")
            for n in mat1:
                print(n)

            print("Enter the elements of Second Matrix:")

            mat2 = [[int(input()) for i in range(column_b)] for i in range(rows_b)]
            for n in mat2:
                print(n)

            res = [[0 for i in range(column_b)] for i in range(rows_a)]

            for i in range(len(mat1)):
                for j in range(len(mat2[0])):
                    for k in range(len(mat2)):
                        res[i][j] += mat1[i][k] * mat2[k][j]
            print("\nmat1 X mat2 is: ")
            for r in res:
                print(r)

        else:
            print("Multiplication cannot be done.Please enter matrix column and row correctly")
        self.choice()

    def transpose(self):
        rows = int(input("Enter the Number of rows : "))
        column = int(input("Enter the Number of Columns: "))

        print("Enter the elements of Matrix:")
        mat1 = [[int(input()) for i in range(column)] for i in range(rows)]
        print("Matrix is: ")
        for n in mat1:
            print(n)

        res = [[mat1[j][i] for j in range(rows)] for i in range(column)]
        

        print("The transpose of Above two Matrices is : ")
        for r in res:
            print(r)
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
        print("------------------------------------------------------------------------------")
        print("Select Yor Choice:")
        print("1.Addition of matrix")
        print("2.Subtraction of matrix")
        print("3.Mutiplication of matrix")
        print("4.Transpose of matrix")
        ch = int(input("Enter Your Choice"))
        if ch == 1:
            self.add()
        elif ch == 2:
            self.sub()
        elif ch == 3:
            self.mul()
        elif ch == 4:
            self.transpose()

m= Matrix()
m.menu()