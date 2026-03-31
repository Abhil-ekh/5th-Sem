#include <bits/stdc++.h>
using namespace std;

long long extendedGCD(long long a, long long b, long long& x, long long& y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long gcd = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    long long a, b, x, y;
    cout << "Enter a and b : ";
    cin >> a >> b;

    long long gcd = extendedGCD(a, b, x, y);

    cout << "gcd = " << gcd << endl;

    if(gcd == 1) {
        long long inverse = (x % b + b) % b;
        cout << "Multiplicative inverse = " << inverse << endl;
    }
    else {
        cout << "Inverse does not exist";
    }

    return 0;
}