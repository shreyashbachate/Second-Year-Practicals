#include <iostream>
#include <fstream>
using namespace std;

void displayMenu(){
  cout<<"\nMAIN MENU"<<endl;
  cout<<"1. Create a file."<<endl;
  cout<<"2. Write information in it."<<endl;
  cout<<"3. Read information from it."<<endl;
  cout<<"4. Close the file."<<endl;
}

int main() {
  fstream f;
  string output;
  string input;        
  char fileName[20]; 
  int r;
  int choice;
  bool fileCreated = false;


  while(1){
    displayMenu();
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice){
      case 1: 
        cout<<"\nEnter file name : ";
        cin >> fileName;
        f.open(fileName, ios::out);
        cout << "\nFile created successfully!"<<endl;
        fileCreated = true;
        break;
      
      case 2:
        if(!fileCreated){
          cout<<"You have to create a file"<<endl;
          break;
        }
        else{
          cout << "Enter data to be written in the file : ";
          cin.ignore();
          getline(cin, input);
          f << input;
          f.close();
          break;
        }


      case 3:
        if(!fileCreated){
          cout<<"You have to create a file"<<endl;
          break;
        }
        else{
          f.open(fileName, ios::in);
          while(!f.eof())
          {
          f >> output;
          cout << output << " ";
        }
        break;
        }
        

      case 4:
        f.close();
        cout << "\nFile closed successfuly"<<endl;
        break;

      default:
        cout << "\nWrong choice"<<endl;
        break; 
    }   

    cout << "\nDo you want to perform it again(y = 1/n = 0) : ";
    cin >> r;

    if(r==0){
      break;
    };

    
  }
} 