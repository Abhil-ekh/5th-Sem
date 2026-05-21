#include <climits>
#include <iostream>
#include <vector>

using namespace std;

pair<vector<int>, vector<int>> prim(const vector<vector<int>>& g) {
  int n = g.size();
  vector<int> key(n, INT_MAX);
  vector<int> parent(n, -1);
  vector<bool> inMST(n, false);
  key[0] = 0;
  for (int i = 0; i < n; i++) {
    int u = -1;
    for (int v = 0; v < n; v++)
      if (!inMST[v] && (u == -1 || key[v] < key[u])) u = v;
    if (u == -1 || key[u] == INT_MAX) break;
    inMST[u] = true;
    for (int v = 0; v < n; v++)
      if (!inMST[v] && g[u][v] < key[v]) {
        key[v] = g[u][v];
        parent[v] = u;
      }
  }

  return {parent, key};
}

int main() {
  int n;

  cout << "Enter no. of vertices: ";
  cin >> n;

  vector<char> name(n);

  cout << "Enter " << n << " vertices: ";

  for (char& c : name) cin >> c;

  vector<vector<int>> g(n, vector<int>(n));

  cout << "Enter adjacency matrix (-1 for no edge):\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];

      if (i != j && g[i][j] == -1) g[i][j] = INT_MAX;
    }
  }

  auto [parent, key] = prim(g);

  int cost = 0;

  cout << "\n--- Prim's MST ---\n\n";
  cout << "Edge\tWeight\n";

  for (int v = 1; v < n; v++) {
    if (parent[v] == -1) {
      cout << "\nGraph is not connected.\n";
      return 0;
    }

    cout << name[parent[v]] << " - " << name[v] << '\t' << key[v] << '\n';

    cost += key[v];
  }

  cout << "\nMinimum Cost = " << cost;

  return 0;
}