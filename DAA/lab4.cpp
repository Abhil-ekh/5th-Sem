#include<iostream>
using namespace std;

int main() {
    int a[9]={1,14,25,7,12,9,80,21,30},key,i;
    cout<<"Enter a number to find in an array: ";
    cin>>key;
    for(i=0;i<9;i++) {
        if(a[i]==key)
            break;
    }
    if(i<9)
        cout<<"Number found in position "<<i+1;
    else
        cout<<"Number doesn't exist in array";
}