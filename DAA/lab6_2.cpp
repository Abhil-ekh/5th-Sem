#include <iostream>
#include <iomanip>
using namespace std;

int binarySearchRecursive(int a[], int low, int high, int key, int &call) {
    // Base case
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    cout << left
         << setw(6)  << call << " | "
         << setw(5)  << low  << " | "
         << setw(6)  << high << " | "
         << setw(10) << (low == high ? "Yes" : "No") << " | "
         << setw(5)  << mid  << " | ";

    if (a[mid] == key) {
        cout << setw(15) << (to_string(a[mid]) + " = " + to_string(key))
             << " | A[mid] == key, Found" << endl;
        return mid;
    }
    else if (a[mid] < key) {
        cout << setw(15) << (to_string(a[mid]) + " < " + to_string(key))
             << " | Search right half" << endl;
        call++;
        return binarySearchRecursive(a, mid + 1, high, key, call);
    }
    else {
        cout << setw(15) << (to_string(a[mid]) + " > " + to_string(key))
             << " | Search left half" << endl;
        call++;
        return binarySearchRecursive(a, low, mid - 1, key, call);
    }
}

int binarySearch(int a[], int n, int key) {
    int call = 1;

    cout << left
         << setw(6)  << "Call" << " | "
         << setw(5)  << "Low"  << " | "
         << setw(6)  << "High" << " | "
         << setw(10) << "Low==High" << " | "
         << setw(5)  << "Mid"  << " | "
         << setw(15) << "A[mid] vs Key" << " | "
         << "Remarks" << endl;

    cout << string(85, '-') << endl;

    return binarySearchRecursive(a, 0, n - 1, key, call);
}

int main() {
    int n = 10;
    int a[] = {2,3,5,7,9,11,13,17,19,23};
    int key;

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(a, n, key);

    cout << endl;
    if (result != -1)
        cout << "Element found at index " << result+1 << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}