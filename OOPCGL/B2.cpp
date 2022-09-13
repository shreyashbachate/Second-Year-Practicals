#include <iostream>
using namespace std;

const int D = 100;

void displayMenu(){
  cout << "\nWhich array do you want to sort ? "<< endl;
  cout << "\n1. Integer Array \n2. Float Array"<<endl;
}

template <typename  T>

class arraySort{
  private:
    int n;
    T a[D];
    int i;

  public:
    arraySort()
    {
      n = 0;
    }

    void inputArray(){
      cout << "\nEnter size of an array : ";
      cin >> n;
      try{
          if(n<0)
          {
            throw n;

          }
        }
        catch(int f){
          cout<<"size cannot be negative "<<f<<endl;
          return inputArray()1
          ;

        }

      for (i = 0; i < n; i++)
      {
        cout << "\nEnter element number - "<<i+1<<" : ";
        cin >> a[i];
      }
    }

    void sortArray(){
      int i,j,min_idx;
      for (i = 0; i < n-1; i++)
      {
        min_idx = i;
        for (j=i+1; j < n; j++)
        {
          if (a[j] < a[min_idx])
          {
            min_idx = j;
          }
        }
        swap(a[min_idx], a[i]);  
      }
    }

    void displayArray()
    {
      for (i = 0; i < n; i++)
      {
        cout << a[i] << " ";
      }
      cout << endl;
    }
};



int main() {
  int choice;
  int response;
  arraySort<int> int_array;
  arraySort<float> float_array;

  while(1){
    displayMenu();
    cout << "\nEnter your choice : ";
    cin >> choice;
    switch(choice){
      
      case 1:
        int_array.inputArray();
        cout << "\nBefore sorting : ";
        int_array.displayArray();
        int_array.sortArray();
        cout << "\nAfter sorting : ";
        int_array.displayArray();
        break;
      
      case 2:
              
        float_array.inputArray();
        cout << "\nBefore sorting : ";
        float_array.displayArray();
        float_array.sortArray();
        cout << "\nAfter sorting : ";
        float_array.displayArray();
        break;
      
      default : 
        cout << "\nWrong Choice, Try again."<<endl;
    }

    cout << "\nDo you want to perform it again?(y=1/n=0) : ";
    cin >> response;

    if (response == 0)
    {
      break;
    }
    
  }

  cout << "\nThank You!";

} 