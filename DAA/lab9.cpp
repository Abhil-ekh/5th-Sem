#include <iostream>
using namespace std;
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
}

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest]) largest = left;

  if (right < n && arr[right] > arr[largest]) largest = right;

  if (largest != i) {
    cout << "Swapping " << arr[i] << " and " << arr[largest] << endl;
    swap(arr[i], arr[largest]);
    printArray(arr, n);
    heapify(arr, n, largest);
  }
}

void buildHeap(int arr[], int n) {
  cout << "\n--- Building Max Heap ---\n";
  for (int i = n / 2 - 1; i >= 0; i--) {
    cout << "\nHeapifying at index " << i << ":" << endl;
    heapify(arr, n, i);
  }
}

void heapSort(int arr[], int n) {
  buildHeap(arr, n);

  cout << "\n--- Heap Sort Process ---\n";
  for (int i = n - 1; i > 0; i--) {
    cout << "\nSwapping root " << arr[0] << " with " << arr[i] << endl;
    swap(arr[0], arr[i]);
    printArray(arr, n);

    cout << "Heapifying reduced heap (size = " << i << ")\n\n";
    heapify(arr, i, 0);
  }
}

int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << "Initial Array:\n";
  printArray(arr, n);

  heapSort(arr, n);

  cout << "Final Sorted Array:\n";
  printArray(arr, n);

  return 0;
}