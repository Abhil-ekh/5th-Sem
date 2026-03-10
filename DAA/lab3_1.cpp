#include<iostream>
using namespace std;
int main() {
    int a=0,b=1,temp=0,n;
    cout<<"Enter nth term of fibonacci sequence: ";
    cin>>n;
    cout<<"Fibonacci sequence up to "<<n<<"th term is"<<endl;
    for(int i=0;i<n;i++) {
        cout<<temp<<"\t";
        a=b;
        b=temp;
        temp=a+b;
    }
}