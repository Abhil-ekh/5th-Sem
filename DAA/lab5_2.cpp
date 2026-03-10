#include<iostream>
#include<iomanip>
using namespace std;

void printArray(int *a, int n) {
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];
}

void selectionSort(int *a,int n) {
    for(int i=0;i<n-1;i++) {
        int min=i;
        cout <<endl<<"Pass " << i + 1 << " : i = " << i <<" min = "<<i<< ", j = "<<i+1<<" to " << n-1 <<endl;
        cout << setw(2)  << "j" << " | "
             << setw(9)  << "A[j]<A[min]"  << " | "
             << setw(6)  << "min=j" << endl;
        cout << string(26, '-') << endl;
        for(int j=i+1;j<n;j++) {
            bool newMin = false;
            cout << setw(2) << j<< " | "
                 << setw(9) <<a[j]<<"<"<<a[min]<< " | ";
            if (a[j] < a[min]) {
                min=j;
                newMin = true;
                 cout << setw(5) <<"min="<<j;
            }
            // if(newMin)
            //     cout << setw(5) <<"min="<<j;
            else
                cout<<setw(5)<<"No";
            cout<<endl;
        }
        if (min != i) {
            cout << endl<< "min != i, swap(A[" << i << "],A[" << min << "])" << endl;
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
        else
           cout << endl << "min == i, no swap " << endl;
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
    selectionSort(a,n);
    cout<<endl<<"The sorted array is: "<<endl;
    printArray(a, n);
    delete [] a;
    return 0;
}