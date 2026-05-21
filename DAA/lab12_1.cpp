#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Item {
  int id, profit, weight;
  double ratio;
};

int main() {
  int n, capacity;

  cout << "Enter number of items : ";
  cin >> n;

  vector<Item> items(n);

  cout << "Enter profit and weight for each item :\n";

  for (int i = 0; i < n; i++) {
    items[i].id = i + 1;

    cout << "Item " << items[i].id << ": ";

    cin >> items[i].profit >> items[i].weight;

    items[i].ratio = (double)items[i].profit / items[i].weight;
  }

  cout << "Enter knapsack capacity : ";
  cin >> capacity;

  sort(items.begin(), items.end(),
       [](const Item& a, const Item& b) { return a.ratio > b.ratio; });

  cout << "\n--- 0-1 Knapsack using Greedy Approach ---\n\n";

  cout << left << fixed << setprecision(2);

  cout << "Items Sorted by P/W Ratio:\n";
  cout << "Item\tProfit\tWeight\tP/W\n";

  for (auto& i : items)
    cout << i.id << '\t' << i.profit << '\t' << i.weight << '\t' << i.ratio
         << '\n';

  int totalWeight = 0, totalProfit = 0;

  cout << "\nSelected Items:\n";
  cout << "Item\tProfit\tWeight\tTotal Weight\tTotal Profit\n";

  for (auto& i : items) {
    if (totalWeight + i.weight <= capacity) {
      totalWeight += i.weight;
      totalProfit += i.profit;

      cout << i.id << '\t' << i.profit << '\t' << i.weight << '\t'
           << totalWeight << "\t\t" << totalProfit << '\n';
    }
  }

  cout << "\nMaximum Profit = " << totalProfit;

  return 0;
}