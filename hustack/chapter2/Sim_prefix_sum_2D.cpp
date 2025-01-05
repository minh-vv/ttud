#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int a[1005][1005];
int f[1005][1005];
int r1, r2, c1, c2;
int res;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test.inp","r",stdin);
    cin >> n >> m;
    for (int i =1 ; i<=n;i++){
        for (int j =1 ; j<=m; j++){
            cin >> a[i][j];
            f[i][j] = a[i][j] + f[i-1][j] + f[i][j-1] - f[i-1][j-1];
        }
    }
    cin >> q;
    for (int i =1 ; i<= q; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        res = f[r2][c2] - f[r2][c1-1] - f[r1-1][c2] + f[r1-1][c1-1];
        cout << res << endl;
    }
}