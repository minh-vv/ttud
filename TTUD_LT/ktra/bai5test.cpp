#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
int d[201][201]; // Ma trận khoảng cách
bool visited[201]; // Đánh dấu điểm đã thăm
vector<pair<int, int>> constraints; // Lưu các cặp (p, q) trong tập hợp P
vector<int> currentPath; // Lưu đường đi hiện tại
int minDistance = INF; // Lưu tổng khoảng cách nhỏ nhất
vector<int> bestPath; // Lưu đường đi tối ưu

// Hàm kiểm tra ràng buộc thứ tự các cặp (p, q)
bool checkConstraints(const vector<int>& path) {
    for (auto [p, q] : constraints) {
        auto itP = find(path.begin(), path.end(), p);
        auto itQ = find(path.begin(), path.end(), q);
        if (itP == path.end() || itQ == path.end() || itP > itQ) {
            return false; // Vi phạm thứ tự
        }
    }
    return true;
}

// Hàm quay lui
void Try(int u, int currentDistance) {
    if (currentPath.size() == n) {
        // Thêm khoảng cách quay về điểm ban đầu
        currentDistance += d[u][currentPath[0]];
        if (currentDistance < minDistance && checkConstraints(currentPath)) {
            minDistance = currentDistance;
            bestPath = currentPath;
        }
        return;
    }

    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            visited[v] = true;
            currentPath.push_back(v);
            Try(v, currentDistance + d[u][v]);
            visited[v] = false;
            currentPath.pop_back();
        }
    }
}

int main() {
    freopen("test.inp", "r", stdin);
    cin >> n;

    // Đọc ma trận khoảng cách
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> d[i][j];

    cin >> m;
    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;
        constraints.emplace_back(p, q);
    }

    memset(visited, false, sizeof(visited));
    visited[1] = true; // Bắt đầu từ điểm 1
    currentPath.push_back(1);

    Try(1, 0);

    cout << minDistance << endl;
    for (int v : bestPath) cout << v << " ";
    cout << bestPath[0]; // Quay lại điểm đầu tiên
    return 0;
}
