#include<iostream>
#include<iomanip>
using namespace std;

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];
}

void bubbleSort(int *a,int n) {
    for(int i=0;i<n-1;i++) {
        cout <<endl<<"Pass " << i + 1 << " : i = " << i << ", j = 0 to " << n - i - 2 <<endl;
        cout << setw(2)  << "j" << " | "
             << setw(9)  << "A[j]>A[j+1]"  << " | "
             << setw(6)  << "Swap" << " | "
             << setw(10) << "Array" <<endl;
        cout << string(n * 5 + 29, '-') << endl;

        for(int j=0;j<n-i-1;j++) {
            bool swapped = false;
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
            cout << setw(2) << j << " | "
                 << setw(9) <<a[j]<<">"<<a[j+1]<< " | "
                 << setw(6) << (swapped ? "Yes" : "No ") << " | ";
            printArray(a, n);
            cout<<endl;
        }
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
    bubbleSort(a,n);
    cout<<endl<<"The sorted array is: "<<endl;
    printArray(a, n);
    delete [] a;
    return 0;
}