// 0-1 Knapsack using Dynamic Programming
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, capacity;

  cout << "Enter number of items : ";
  cin >> n;

  vector<int> profit(n + 1), weight(n + 1);

  cout << "Enter profit and weight for each item :\n";

  for (int i = 1; i <= n; i++) {
    cout << "Item " << i << ": ";
    cin >> profit[i] >> weight[i];
  }

  cout << "Enter knapsack capacity : ";
  cin >> capacity;

  vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= capacity; w++) {
      if (weight[i] <= w)
        dp[i][w] = max(dp[i - 1][w], profit[i] + dp[i - 1][w - weight[i]]);
      else
        dp[i][w] = dp[i - 1][w];
    }
  }

  cout << "\n--- 0-1 Knapsack using Dynamic Programming ---\n\n";

  cout << "DP Table:\n";

  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= capacity; w++) cout << dp[i][w] << "\t";
    cout << endl;
  }

  vector<int> selected;

  int w = capacity;

  for (int i = n; i >= 1; i--) {
    if (dp[i][w] != dp[i - 1][w]) {
      selected.push_back(i);
      w -= weight[i];
    }
  }

  reverse(selected.begin(), selected.end());

  int totalWeight = 0, totalProfit = 0;

  cout << "\nSelected Items:\n";
  cout << "Item\tProfit\tWeight\tTotal Weight\tTotal Profit\n";

  for (int i : selected) {
    totalWeight += weight[i];
    totalProfit += profit[i];

    cout << i << '\t' << profit[i] << '\t' << weight[i] << '\t' << totalWeight
         << "\t\t" << totalProfit << endl;
  }

  cout << "\nMaximum Profit = " << dp[n][capacity];

  return 0;
}