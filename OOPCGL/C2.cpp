#include<iostream>
#include<iterator>
#include<map>
#include<string>

using namespace std;

int main()
{
    int count=0, population =0,ch;
    string st, key;

    map<string, int> states;

    map<string, int> :: iterator itr;

    while(1)
    {
        
        cout<<"\n ************ \n";
        cout<<"\n1.Enter States and Population\n2.Display\n3.Search\n4.Exit\n";
        cout<<"\n Enter Your Choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
            cout << "\nEnter number of states : ";
            cin >> count;
            while(count > 0)
            {
                cout << "\nEnter state name : ";
                cin.ignore();
                getline(cin, st);
                cout << "\nEnter population : ";
                cin >> population;
                states.insert(pair<string, int>(st, population));
                count--;
            }
            break;
        }
        
        case 2:
        {
            cout << "\n-------------- States and Population --------------"<<endl;
            for(itr = states.begin(); itr != states.end(); itr++)
            {
                cout << "\t" << itr->first << "\t" << itr->second << endl;
            }   
            break;
        }

        case 3:
        {
            cout << "\nEnter the state : ";
            cin >> key;

            auto val = states.find(key);

            if(states.count(key) == 0)
            {
                cout << "\nState is not present";
            }
            else{
                cout << "\nPopulation : " << val->second;
            }
            break;
        }
        default :
        {
        cout<<"\n You Entered Wrong Choice";
        cout<<"\n Exit Thank You";
        break;
        }
        } 
        if(ch>=3)
        break;  
    }   

}
    