#include<iostream>

using namespace std;

class complex{
    private :
    int real, imag;

    public:
    complex(){
        real = 0;
        imag = 0;
    }
    complex operator+(complex &c)
    {
        complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    complex operator*(complex &c)
    {
        complex temp;
        temp.real = real*c.real - imag*c.imag;
        temp.imag = (real*c.imag) + (imag *c.real);
        return temp;

    }

    friend ostream& operator <<(ostream& out, complex&);
    friend istream& operator >>(istream& in, complex&);
};

istream& operator>>(istream &in, complex &c)
{

    cout << "\nEnter real part : ";
    in>>c.real;
    cout << "\nEnter imaginary part : ";
    in >> c.imag;
    return in;

}

ostream& operator<<(ostream& out, complex &c)
{
    out << c.real << " + " << c.imag << "i";
    return out;
}


int main()
{
    complex c1,c2,c3;
    int choice, yn;
    bool repeatAgain = true;

    while(repeatAgain)
    {
        cout << "\n**********MAIN MENU**********"<<endl;
        cout << "1. Display default constructor value"<<endl;
        cout << "2. Addition of two complex numbers"<<endl;
        cout << "3. Multiplication of 2 complex numbers"<<endl;

        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1 :
                cout << c1;
                break;

            case 2:
                cout << "\nEnter first complex number";
                cin >> c1;
                cout << "\nEnter second complex number";
                cin >> c2;
                cout << "Addition of 2 complex numbers is : ";
                c3 =  c1+c2;
                cout << c3;
                break;


            case 3:
                cout << "\nEnter first complex number";
                cin >> c1;
                cout << "\nEnter second complex number";
                cin >> c2;
                cout << "\n\nMultiplication of 2 complex numbers is : ";
                c3 =  c1*c2;
                cout << c3;
                break;

            default:
                cout << "\nWrong choice, please try again.";
                break;            

        }

        cout << "\n\nDo you want to perform again? (y=1/n=0) : ";
        cin >> yn;
        if(yn == 0)
            repeatAgain = false;
    }

    cout << "\n\nTHANK YOU!!";
}