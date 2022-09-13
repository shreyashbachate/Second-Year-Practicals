#include<iostream>
#include<string>
using namespace std;

class publication
{


    public:
    string title;
    float prices;
    publication()
    {
        title="";
        prices=0.0;
    }
    void get_data()
    {
        cout<<"\nEnter Title :";
        cin.ignore();
        getline(cin,title);
        cout<<"\nEnter Price : ";
        cin>>prices;
        try
        {
            if(prices<0.0)
            throw prices;
        }
        catch(float r)
        {
            cout<<"\n Error: Invalid Price : "<<prices;
            prices=0;
        }
    }
    void put_data()
    {

        cout<<"\n Title :"<<title;
        cout<<"\n Price :"<<prices;
    }
};

class book: public publication
    {

    int pages;
    public:
    book(){
        pages=0;
    }
    void get_data()
    {
        publication::get_data();
        cout<<endl;
        cout<<"Enter Page Count : \n";
        try
        {
            cin>>pages;
            if(pages<0)
            throw pages;
        }
        catch(int f)
        {
            cout<<"\n error: pages not valid :"<<f<<endl;
            pages=0;
            title="";
            prices=0;
        }
    }

    void put_data()
    {
        publication::put_data();

        cout<<"\n Pages Are :"<<pages<<endl;
    }
};
   
class tape: public publication
{

    float playtime;
    public:
    tape()
    {
        playtime=0.0;
    }
    void get_data()
    {
        publication::get_data();
        cout<<"Enter Play Time Of Cassette : ";
        cin>>playtime;
        try
        {
            if(playtime<0.0)
            throw playtime;
        }
        catch(float r)
        {
            cout<<"\n Error: Invalid Playtime : "<<playtime;
            playtime=0.0;
            prices=0.0;
            title="";
        }
    }
    void put_data()
    {
        publication::put_data();

        cout<<"\n Playtime is : "<<playtime<<endl;
    }
};
int main()//main program
{
    book b[10];// arrray of objects
    tape t[10];
    int choice=0,bookCount=0,tapeCount=0;
    cout<<"-----------------------";
    do
    {
        cout<<"\n 1. Add book ";
        cout<<"\n 2. Add tape ";
        cout<<"\n 3. Display book ";
        cout<<"\n 4. Display tape";
        cout<<"\n 5. Exit:"<<endl;
        cout<<"\n Enter Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
            cout<<"\n--------------\n";
            cout<<"Add Book: \n";
            b[bookCount].get_data();
            bookCount++;
            break;
        }

        case 2:
        {
            cout<<"\n--------------\n";
            cout<<"Add Tape: \n";
            t[tapeCount].get_data();
            tapeCount++;
            break;
        }

        case 3:
        {
            cout<<"\n---------------BOOKS------------\n";
            for(int j=0;j<bookCount;j++)
            {
            b[j].put_data();
            }
        break;
        }

        case 4:
        {
            cout<<"\n---------------TAPES------------\n";
            for(int j=0;j<tapeCount;j++)
            {
            t[j].put_data();
            }
            break;
        }
        case 5:
        {
            cout<<"Program ExitedSuccessfully"<<endl;
            exit(0);

        }
        default:
        {
            cout<<"\n Invalid";
        }
    }
    }while(choice!=5);
return 0;
}