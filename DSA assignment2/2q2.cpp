#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Test{
    public:

    int bubbleSort(int array[], int n){
        for(int i=0;i<n;i++){
            int flag=true;
            for(int j=0;j<n-i-1;j++){
                
                if(array[j]>array[j+1]){
                    flag=false;
                    int temp;
                    temp=array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;
                }
            }
            if(flag){
                break;
            }
        }
    }
};

int main(){
    srand(time(0));
    Test t;
    int n;
    cout<<"Enter the amount of integers to be chosen: "<<endl;
        cin>>n;
        cin.ignore();
        int array[n];
        for(int i=0;i<n;i++){
            array[i]=(rand() % 99)+1;
        }
    cout<<"Array before sorting: "<<endl;    
        for(int j=0;j<n;j++){
            cout<<array[j]<<" ";
        }
        cout<<endl;
        t.bubbleSort(array,n);
    cout<<"Array after sorting: "<<endl; 
        for(int k=0;k<n;k++){
            cout<<array[k]<<" ";
        }
    
    return 0;

}