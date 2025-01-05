#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1000001];
int st[21][1000001];
int l,r;
int res;
void preprocessing (){
    for (int i=0; i< n; i++) st[0][i] = i;
    for (int i=1; (1 << i) <= n ; i++){
        for (int j=0; j + (1 << i) -1 < n ; j++){
            int x = st[i-1][j];
            int y = st[i-1][j +(1 << (i-1))];
            st[i][j] = (a[x] < a[y]) ? x : y;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test.inp","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++)  cin >> a[i];
    preprocessing();
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        int k = log2(r-l+1);
        int x = st[k][l];
        int y = st[k][r - (1<<k)+1];
        res += (a[x] <= a[y]) ? a[x] : a[y];
    }
    cout << res;
}