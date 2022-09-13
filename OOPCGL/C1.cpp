#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class PersonalRecord
{
    private:
    int id;
    string name, dob;
    long telenumber;

    public:
    PersonalRecord()
    {
        id = 0;
        name = "";
        dob = "";
        telenumber = 0;
    }

    PersonalRecord(int i, string nm, string db, long num)
    {
        id = i;
        name = nm;
        dob = db;
        telenumber = num;
    }

    
    string getName(){
        return name;
    }
    
    int getId(){
        return id;
    }

    string getDOB(){
        return dob;
    }

    long getNum(){
        return telenumber;
    }
};

vector<PersonalRecord> records;
void dataEntry();
void display();
void recordOrdered();
void search();

bool compare(PersonalRecord& record1, PersonalRecord& record2)
{
    return record1.getId() < record2.getId();
}

int main()
{
    int count,temp;
    
  while(1)
  {
    cout<<"\n***********\n";
    cout<<"1.Add Record \n2.Display Record \n3.Ordered Record \n4.Search Record\n5.Exit\n";
    cout<<"Enter your choice :- ";
    cin>>temp;
    
    switch(temp)
    {
      case 1:
    {
      cout << "\nEnter number of IDs : ";
      cin >> count;
      while(count > 0)
    {
        dataEntry();
        count--;
    }
    break;

    }
    case 2:
    {
      display();
      break;
    }

    case 3:
    {
      recordOrdered();
      break;
    }

    case 4:
    {
      search();
      break;
    }

    default:
    {
    cout<<"You Entered Wrong Choice\n";
    cout<<"Exit Thank You\n";
    break;
    }  
  }
  if(temp>=5)
  break;
  }
    
    
    return 0;
}

void dataEntry()
{
    int i;
    string nm, db;
    long num;

    cout<<"\n\nEnter the ID : ";
    cin>>i;
    cout<<"\nEnter name : ";
    cin >> nm;
    cout << "\nENter Date of Birth : ";
    cin >> db;
    cout << "\nEnter telephone number : "<<endl;
    cin >> num;
    PersonalRecord obj(i,nm,db,num);
    records.push_back(obj);
}

void display()
{
    for(int i = 0; i < records.size(); i++)
    {
        cout << records[i].getId() << ", " << records[i].getName() << ", " << records[i].getDOB() << ", " << records[i].getNum() << endl;
    }
}

void recordOrdered()
{
    sort(records.begin(), records.end(), compare);
    display();
}

void search()
{
    int flag = 0, sid = 0;
    cout << "\nEnter the ID to search : ";
    cin >> sid;
    for(int i=0; i<records.size(); i++)
    {
        if(sid == records[i].getId())
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        cout<<"\nElement not found"<<endl;
    }
    else{
        cout << "\nElement found"<<endl;
    }
}