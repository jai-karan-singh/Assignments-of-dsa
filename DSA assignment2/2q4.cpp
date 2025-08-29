#include<iostream>
#include<cstring>
using namespace std;

class A{
    public:
    char name1[20];
    char name2[20];
    char conc[40];
    int i=0,j=0;
    void concatenate(){
        cout<<"Enter string 1: ";
        cin.getline(name1,20);
        cout<<"\nEnter string 2: ";
        cin.getline(name2,20);

        while(name1[i] != '\0'){
            conc[i]=name1[i];
            i++;
        }

        while(name2[j] != '\0'){
            conc[i]=name2[j];
            i++;
            j++;
        }
        conc[i]='\0';

        cout<<"Concatenated string is: "<<conc<<endl;
    }
        
};


class B{
    public:
    char str[100];
    char revStr[100];
    void reverse(){
            int i=0;
        cout<<"Enter string: ";
        cin.getline(str,100);
        int n= strlen(str);
        while(str[i]!='\0'){
            revStr[n-i-1]=str[i];
            i++;

        }
        revStr[i]='\0';
        cout<<"Reversed String is: "<<revStr<<endl;
    }
};


class C{
    public:
    char string[100];
    char noVow[100];
    void removeVow(){
        int i=0;
        int j=0;
        cout<<"Enter string: \n";
        cin.getline(string,100);

        int n= strlen(string);

        while(string[i] != '\0'){
                char ch;
                ch=string[i];
                if(!(ch=='A' ||ch=='a' ||ch=='E' ||ch=='e' ||ch=='I' ||ch=='i' ||ch=='O' ||ch=='o' ||ch=='U' ||ch=='u') ){
                    noVow[j]=ch;
                    j++;
                }
                i++;
            }
            noVow[j]='\0';
        cout<<"String with no vowels: "<<noVow<<endl;
        }
        
    };


    class D{
        public:
        char alpha[100];
        void alphaOrdered(){
            int i=0,j=0;
             cout<<"Enter string: \n";
        cin.getline(alpha,100);

        int n= strlen(alpha);

         for(i=0;i<n-1;i++){
            for(j=0;j<n-1-i;j++){
                int temp1=alpha[j];
                int temp2=alpha[j+1];
                if(alpha[j]>='A' && alpha[j]<='Z'){
                temp1=alpha[j]+32;
            }
             if(alpha[j+1]>='A' && alpha[j+1]<='Z'){
                temp2=alpha[j+1]+32;
             }
            if(temp1>temp2){
                    char temp=alpha[j];
                    alpha[j]=alpha[j+1];
                    alpha[j+1]=temp;
            }
          
        }
    }
        alpha[n]='\0';
        cout<<"Alphabetic order of string is: "<<alpha<<endl;
}
    };


  class E{
        public:
        char stringg[100];
        char switched[100];

        void switchString(){
            int i=0,j=0;
            cout<<"Enter string: \n";
        cin.getline(stringg,100);

        int n= strlen(stringg);

        for(i=0;i<n;i++){
            switched[i]=stringg[i];
        }
            for(i=0;i<n;i++){
                if(stringg[i]>='A' && stringg[i]<='Z'){
                    switched[i]=stringg[i]+32;
                }
                else if(stringg[i]>='a' && stringg[i]<='z'){
                    switched[i]=stringg[i]-32;
                }
            }
            switched[i]='\0';
            cout<<"Switched string is: "<<switched<<endl;
        }
    };
int main(){
    A a;
   // a.concatenate();
    B b;
   // b.reverse();
   C c;
   // c.removeVow();
   D d;
   // d.alphaOrdered();
   E e;
   // e.switchString();
    return 0;
}