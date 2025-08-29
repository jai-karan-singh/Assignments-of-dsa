#include <iostream>
using namespace std;
#define MAX 100

class Stack{
  int array[MAX];
  int top;
  public:
  Stack(){
      top=-1;
  }
 
  void push(int x){
      if(top==MAX-1){
          cout<<"Stack is full\n";
      }
          else array[++top]= x;
  }
  void pop(){
      if (top==-1){
          cout<<"Stack is empty\n";
      }
          else cout<<"Popped "<< array[top--]<<endl;
  }
  bool isEmpty(){
      return (top==-1);
  }
  bool isFull(){
      return (top==MAX-1);
  }
  void display(){
      if(top==-1){
          cout<<"Stack is empty\n";
      }
          else for(int i=top;i>=0;i--){
              cout<<array[i]<<" ";
              cout<<endl;
      }
  }
  void peek(){
      if(top==-1){
          cout<<"Stack is empty\n";
      }
          else cout<<"Top: "<<array[top]<<endl;
  }
};

int main() {
   Stack s;
   int choice,value;
   while(1){
       cout<<"1.Push\n2.Pop\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n7.Exit\n";
       cin>>choice;
       cin.ignore();
       switch(choice){
           case 1 : cout<<"Value: ";
                    cin>>value;
                    s.push(value);
                    break;
           case 2 : s.pop();
                    break;
           case 3 : cout<<(s.isEmpty() ? "Empty\n" : "Not Empty\n");
                    break;
           case 4 : cout<<(s.isFull() ? "Full\n" : "Not Full\n");
                    break;
           case 5 : s.display();
                    break;
           case 6 : s.peek();
                    break;
           case 7 : return 0;
           default: cout<<"Invalid\n";
       }
   }

    return 0;
}