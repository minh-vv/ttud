#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> toado[1001];

struct edge {
    int x, y, w;
};

vector<edge> canh;
vector<edge> existing_edges;
int parent[1001];
int sz[1001];
int numComponents;

void setmem() {
    numComponents = n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int findSet(int u) {
    if (u != parent[u])
        parent[u] = findSet(parent[u]);
    return parent[u];
}

bool unionSet(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if (u == v)
        return false;
    // Union by size
    if (sz[u] < sz[v])
        swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    numComponents--;
    return true;
}

void setw() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int dx = toado[i].first - toado[j].first;
            int dy = toado[i].second - toado[j].second;
            int w = dx * dx + dy * dy;
            canh.push_back({i, j, w});
        }
    }
}

void inp() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> toado[i].first >> toado[i].second;
    }
    setw();
    cin >> m;
    setmem(); // Initialize Union-Find structure
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int dx = toado[x].first - toado[y].first;
        int dy = toado[x].second - toado[y].second;
        int w = dx * dx + dy * dy;
        edge e = {x, y, w};
        existing_edges.push_back(e);
        // Union the existing edges
        unionSet(x, y);
    }
}

bool cmp(const edge &e1, const edge &e2) {
    return e1.w < e2.w;
}

void kruskal() {
    int total_weight = 0;
    sort(canh.begin(), canh.end(), cmp);
    for (const edge &e : canh) {
        if (numComponents == 1)
            break;
        if (unionSet(e.x, e.y)) {
            existing_edges.push_back(e);
            total_weight += e.w;
        }
    }
    if (numComponents != 1) {
        cout << -1 << endl;
    } else {
        cout << total_weight << endl;
    }
}

int main() {
    inp();
    kruskal();
    return 0;
}