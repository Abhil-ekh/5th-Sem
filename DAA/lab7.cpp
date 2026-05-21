#include <iostream>
using namespace std;

struct Pair {
    int min;
    int max;
};

int comparisons = 0; 

Pair minMax(int a[], int low, int high) {
    Pair result, left, right;

    if (low == high) {
        result.min = result.max = a[low];
        return result;
    }

    if (high == low + 1) {
        comparisons++;
        if (a[low] < a[high]) {
            result.min = a[low];
            result.max = a[high];
        } 
        else {
            result.min = a[high];
            result.max = a[low];
        }
        return result;
    }

    int mid = (low + high) / 2;
    left = minMax(a, low, mid);
    right = minMax(a, mid + 1, high);

    comparisons++;
    result.min = (left.min < right.min) ? left.min : right.min;
    comparisons++;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Pair result = minMax(a, 0, n - 1);

    cout << "\nMinimum element = " << result.min << endl;
    cout << "Maximum element = " << result.max << endl;

    return 0;
}