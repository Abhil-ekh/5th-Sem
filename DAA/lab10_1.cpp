#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    int value;
    int weight;
    int index; 
};

bool compare(const Item& a, const Item& b) {
    return (long long)a.value * b.weight > (long long)b.value * a.weight;
}

void fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    cout << "\nItems after sorting by value/weight ratio:\n";
    cout << "Item\tValue\tWeight\tRatio\n";
    for (const auto& item : items) {
        cout << item.index << "\t"
             << item.value << "\t"
             << item.weight << "\t"
             << fixed << setprecision(2)
             << (double)item.value / item.weight << endl;
    }
    double totalValue = 0.0;
    cout << "\nSimulation of Knapsack Filling:\n";
    for (const auto& item : items) {
        if (item.weight <= W) {
            cout << "Taking FULL item " << item.index << "\n";
            W -= item.weight;
            totalValue += item.value;
            cout << "Remaining Capacity: " << W << endl;
        }
        else {
            double fraction = (double)W / item.weight;
            cout << "Taking FRACTION " << fixed << setprecision(2)
                 << fraction << " of item " << item.index << "\n";
            totalValue += item.value * fraction;
            cout << "Knapsack is now full.\n";
            break;
        }
    }
    cout << "\nMaximum Value Obtained = " << totalValue << endl;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        items[i].index = i + 1;
        cout << "\nEnter value of item " << i + 1 << ": ";
        cin >> items[i].value;
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> items[i].weight;
    }
    cout << "\nEnter capacity of knapsack: ";
    cin >> W;
    fractionalKnapsack(W, items);
    return 0;
}