#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

double bound(const vector<pair<int, int>>& items, int n, int cap, int idx,
             int w, int p) {
  double b = p;
  for (int i = idx + 1; i < n && w < cap; i++) {
    if (w + items[i].second <= cap) {
      w += items[i].second;
      b += items[i].first;
    } else {
      b += (double)(cap - w) * items[i].first / items[i].second;
      break;
    }
  }
  return b;
}

void solve(int idx, int w, int p, const vector<pair<int, int>>& items, int n,
           int cap, vector<int>& cur, vector<int>& best, int& bestP) {
  if (w > cap) return;
  if (p > bestP) {
    bestP = p;
    best = cur;
  }
  if (idx == n - 1 || bound(items, n, cap, idx, w, p) <= bestP) return;
  int nx = idx + 1;
  if (w + items[nx].second <= cap) {
    cur[nx] = 1;
    solve(nx, w + items[nx].second, p + items[nx].first, items, n, cap, cur,
          best, bestP);
  }
  cur[nx] = 0;
  solve(nx, w, p, items, n, cap, cur, best, bestP);
}

int main() {
  int n, capacity;
  cout << "Enter number of items : ";
  cin >> n;
  vector<pair<int, int>> items(n);  // {profit, weight}
  vector<int> origId(n);
  cout << "Enter profit and weight for each item :\n";
  for (int i = 0; i < n; i++) {
    origId[i] = i + 1;
    cout << "Item " << origId[i] << ": ";
    cin >> items[i].first >> items[i].second;
  }
  cout << "Enter knapsack capacity : ";
  cin >> capacity;

  // Sort by profit/weight ratio descending
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int a, int b) {
    return (double)items[a].first / items[a].second >
           (double)items[b].first / items[b].second;
  });
  vector<pair<int, int>> sorted(n);
  vector<int> sortedId(n);
  for (int i = 0; i < n; i++) {
    sorted[i] = items[idx[i]];
    sortedId[i] = origId[idx[i]];
  }

  int bestProfit = 0;
  vector<int> cur(n, 0), best(n, 0);
  solve(-1, 0, 0, sorted, n, capacity, cur, best, bestProfit);

  cout << "\n--- 0-1 Knapsack using Backtracking ---\n\n";
  cout << "Selected Items:\n";
  cout << "Item\tProfit\tWeight\tTotal Weight\tTotal Profit\n";
  int tw = 0, tp = 0;
  for (int i = 0; i < n; i++) {
    if (best[i]) {
      tw += sorted[i].second;
      tp += sorted[i].first;
      cout << sortedId[i] << '\t' << sorted[i].first << '\t' << sorted[i].second
           << '\t' << tw << "\t\t" << tp << '\n';
    }
  }
  cout << "\nMaximum Profit = " << bestProfit;
  return 0;
}