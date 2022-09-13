#include<iostream>
#include<fstream>
using namespace std;

class Student
{
public:
    string name;
    string rollno;
    char cl[5];

    void accept();

    void display();
};

void Student::accept()
{
    cout<<"\nEnter name : ";
    cin>>name;
    cout << "\nEnter roll number : ";
    cin>>rollno;
    cout<<"\nEnter class : ";
    cin>>cl;
}

void Student::display()
{
    cout<<"\nName: "<<name;
    cout<<"\nRoll number : "<<rollno;
    cout<<"\nClass : "<<cl;
}
void displayMenu(){
  cout<<"\n\nMAIN MENU"<<endl;
  cout<<"1. Write in file."<<endl;
  cout<<"2. Read from file."<<endl;
  cout<<"3. Close file."<<endl;
  cout<<"4. Exit"<<endl;
}
int main()
{
    Student obj[5];
    fstream file;
    int i,n,ch;
    bool repeatAgain = true;

    while(repeatAgain)
    {
        displayMenu();
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
            case 1:
                file.open("Database.txt",ios::out);
                if(file)
                {
                    cout<<"\n How many Student information do you need to store?";
                    cin>>n;
                    for(i=1;i<=n;i++)
                    {
                        obj[i].accept();
                        file.write((char*)&obj[i],sizeof obj[i]);
                    }
                }
                else
                {   
                    cout<<"File dosen't exists";
                }
                break;
            
            case 2:
                file.open("Database.txt",ios::in);        
                cout<<"\n Information of Students is as follows:";
                for(i=1;i<=n;i++)
                {
                    file.read((char*)&obj[i],sizeof obj[i]);
                    obj[i].display();
                }
                
                break;

            case 3:
                file.close();
                cout << "\nFile closed successfully!";
                break;
            
            case 4:
                repeatAgain = false;
                break;
            
            default:
                cout << "\nWrong choice! please try again later.";
        }

    }
    

    
    return 0;
}