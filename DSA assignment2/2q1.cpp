#include<iostream>
using namespace std;

class Test{
    public:
    int binarySearch(int x, int array[], int n){
        int l=0;
        int r=n-1;
        
     
         while(l<=r){
           int m=(l+(r))/2;
        if(array[m]==x){
            return m;
        }
        if(array[m]<x){
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    return -1;
}

    int linearSearch(int y, int array[], int n){
        int l=0;
        int r=n-1;

        while(l<=r){
            for(int i=0;i<n;i++){
                if(array[i]==y){
                    return i;
                }
            }
        }
        return -1;
    }

};

int main(){
    Test t;
    int n,x,y;
    cout<<"Enter the amount of integers to be chosen: ";
        cin>>n;
        cin.ignore();
        int array[n];
        for (int i=0;i<n;i++){
            array[i]=i+1;
        }
        
        for(int j=0;j<n;j++){
            cout<<array[j]<<" ";
        }

        cout<<"\nEnter integer to find using Binary Search: "<<endl;
        cin>>x;
        cin.ignore();
   int result=t.binarySearch(x,array,n);
   if(result==-1){
    cout<<"Integer not found."<<endl;
   }
   else cout<<"Integer found at index "<<result<<endl;


    cout<<"\nEnter integer to find using Linear Search: "<<endl;
        cin>>y;
        cin.ignore();
        int Result=t.linearSearch(y,array,n);
      if(Result==-1){
    cout<<"Integer not found."<<endl;
   }
   else cout<<"Integer found at index "<<Result<<endl;  

    return 0;
}