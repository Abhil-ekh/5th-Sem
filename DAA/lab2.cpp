#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int iteration = 1;

    int w1 = 10, w2 = 10, w3 = 10, w4 = 12;
    cout << "\n"
         << setw(w1) << "Iteration" << "|"
         << setw(w2) << "a" << "|"
         << setw(w3) << "b" << "|"
         << setw(w4) << "r = a % b" << endl;

    cout << string(w1 + w2 + w3 + w4 + 3, '-') << endl;

    while (b != 0) {
        int r = a % b;

        cout << setw(w1) << iteration << "|"
             << setw(w2) << a << "|"
             << setw(w3) << b << "|"
             << setw(w4) << r << endl;

        a = b;
        b = r;
        iteration++;
    }

    cout << "\nGCD = " << a << endl;

    return 0;
}