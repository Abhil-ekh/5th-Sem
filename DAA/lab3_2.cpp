#include<iostream>
using namespace std;

int fib(int n) {
    if(n==0)
        return 0;
    if (n==1)
        return 1;
    else 
        return fib(n-1) + fib(n-2);
}

int main() {
    int a=0,b=1,temp=0,n;
    cout<<"Enter nth term of fibonacci sequence: ";
    cin>>n;
    cout<<"Fibonacci sequence up to "<<n<<"th term is"<<endl;
    for(int i=0;i<n;i++) {
        cout<<fib(i)<<"\t";
    }
}