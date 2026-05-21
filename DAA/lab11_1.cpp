#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct Edge {
  char u, v;
  int w;
};

struct DSU {
  vector<int> p, r;

  DSU(int n) : p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }

  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (r[a] < r[b]) swap(a, b);
    p[b] = a;
    if (r[a] == r[b]) r[a]++;

    return true;
  }
};

int main() {
  int n, m;

  cout << "Enter vertices & edges : ";
  cin >> n >> m;

  vector<Edge> edges(m);

  cout << "Enter edges (u v w) :\n";

  for (auto& e : edges) cin >> e.u >> e.v >> e.w;

  sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });

  DSU dsu(26);

  int cost = 0, used = 0;

  cout << "\nKruskal's MST \n";
  cout << "Edge\tWeight\n";

  for (auto& e : edges) {
    int u = toupper(e.u) - 'A';
    int v = toupper(e.v) - 'A';

    if (dsu.unite(u, v)) {
      cout << e.u << " - " << e.v << '\t' << e.w << '\n';
      cost += e.w;
      used++;
    }
  }

  if (used != n - 1)
    cout << "\nGraph is not connected.\n";
  else
    cout << "\nMinimum Cost = " << cost;
}