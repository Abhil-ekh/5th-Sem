#include<iostream>
#include<iomanip>
using namespace std;

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];
}

void insertionSort(int *a,int n) {
    for(int i=1;i<n;i++) {  
        int temp = a[i];
        int j=i-1;
        bool insert=false;
        cout <<endl<<"Pass " << i << " : i = " << i <<" temp = A["<<i<< "], j = "<<j<<" to " << 0 <<endl;
        cout << setw(2)  << "j" << " | "
             << setw(10)  << "A[j]>temp"  << " | "
             << setw(6)  << "A[j+1]=A[j]" << endl;
        cout << string(30, '-') << endl;
        while(j>=0 && a[j]>temp) {
            cout << setw(2) << j<< " | "
                 << setw(7) << a[j]<<">"<<temp<< " | "
                 << setw(6) << a[j+1] << "=" <<a[j] << endl;
            a[j + 1] = a[j];
            j--;
            insert=true;
        }
        if(!insert)
            cout << setw(2) << j<< " | "
                 << setw(7) << a[j]<<">"<<temp<< " | "
                 << setw(6) << "No" << endl;
        if(j<0)
            cout << setw(2) << "-1"<< " | "
                 << setw(10) << "-"<< " | "
                 << setw(6) << "-" << endl;  
        a[j+1]=temp;
        cout<<"Array after pass "<<i+1<<":";
        printArray(a,n);
        cout<<endl;        
    }
}

int main() {
    int *a, n;
    cout << "Enter array size : ";
    cin >> n;
    a = new int[n];
    cout << "Enter " << n << " elements : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insertionSort(a,n);
    cout<<endl<<"The sorted array is: "<<endl;
    printArray(a, n);
    delete [] a;
    return 0;
}