#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX_N = 1000000;
const int MAX_LOG = 20;  // log2(10^6) ≈ 20

// Mảng a để lưu giá trị mảng đầu vào
vector<int> a(MAX_N);
// Bảng st[i][j] lưu chỉ số phần tử nhỏ nhất trong đoạn [j, j + 2^i - 1]
vector<vector<int>> st(MAX_LOG, vector<int>(MAX_N));

// Hàm tiền xử lý (preprocessing) Sparse Table
void buildSparseTable(int n) {
    // Khởi tạo bảng st[0] với chính các chỉ số mảng
    for (int i = 0; i < n; i++) {
        st[0][i] = i;
    }

    // Tính toán bảng st[i][j] cho i > 0
    for (int i = 1; (1 << i) <= n; i++) {
        for (int j = 0; j + (1 << i) - 1 < n; j++) {
            int x = st[i - 1][j];
            int y = st[i - 1][j + (1 << (i - 1))];
            // Chọn chỉ số của phần tử nhỏ hơn
            st[i][j] = (a[x] < a[y]) ? x : y;
        }
    }
}

// Hàm truy vấn Sparse Table để lấy chỉ số phần tử nhỏ nhất trong đoạn [L, R]
int query(int L, int R) {
    int length = R - L + 1;
    int k = log2(length);  // Tính log2(length)
    int x = st[k][L];  // Chỉ số của phần tử nhỏ nhất trong đoạn [L, L + 2^k - 1]
    int y = st[k][R - (1 << k) + 1];  // Chỉ số của phần tử nhỏ nhất trong đoạn [R - 2^k + 1, R]
    return (a[x] < a[y]) ? x : y;  // Trả về chỉ số của phần tử nhỏ nhất
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    //freopen("test.inp","r",stdin);

    int n, m;
    cin >> n;
    
    // Đọc mảng a
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Xây dựng Sparse Table
    buildSparseTable(n);

    // Đọc số lượng truy vấn
    cin >> m;
    
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        // Truy vấn để tìm phần tử nhỏ nhất trong đoạn [l, r]
        int idx = query(l, r);
        //sum += a[idx];  // Thêm giá trị phần tử nhỏ nhất vào tổng
        cout << idx << endl;
    }

    // In ra kết quả
    cout << sum << endl;

    return 0;
}