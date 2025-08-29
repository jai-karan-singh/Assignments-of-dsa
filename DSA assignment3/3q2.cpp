#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100

class Stack{
  char array[MAX];
  int top;
  public:
  Stack(){
      top=-1;
  }
 
  void push(char x){
        array[++top]= x;
  }
  char pop(){
        return array[top--];
  }
  bool isEmpty(){
      return (top==-1);
  }
};

int main() {
    char str[MAX];
    cout<<"Enter a string: \n";
    cin>>str;
    Stack s;
    int length=strlen(str);
    for(int i=0;i<length;i++){
        s.push(str[i]);
    }
    cout<<"Reversed using Stack: ";
    while(!s.isEmpty()){
        cout<<s.pop();
    }
    return 0;
}