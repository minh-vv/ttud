#include <bits/stdc++.h>
using namespace std;

int n, t;
int p[100001];

int main() {
    freopen("test.inp", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        int count = 0; // Số bước nhảy
        int i = 1;     // Vị trí hiện tại

        while (i < n) {
            count++;
            int maxS = 0, node = -1;

            // Tìm bước nhảy tốt nhất
            for (int j = i + 1; j <= i + p[i] && j <= n; j++) {
                if (p[j] > maxS) {
                    maxS = p[j];
                    node = j;
                }
            }

            if (node == -1) break; // Không có bước nhảy hợp lệ

            i = node; // Nhảy tới vị trí tốt nhất
        }

        if (i >= n) {
            cout << count << endl;
        } else {
            cout << -1 << endl; // Không thể đến cuối
        }
    }
    return 0;
}
