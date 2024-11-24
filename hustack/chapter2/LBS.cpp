#include <bits/stdc++.h>
using namespace std;

int n,q;
int a[1000005];
int res = -1;
int l = 1, r;
int s = 0;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("test.inp","r",stdin);
    cin >> n >> q;
    for (int i = 1;i <=n ; i++){
        cin >> a[i];
    }
    for (r = 1; r <= n; r++){
        s = s + a[r];
        while (s > q){
            s -= a[l];
            l++;
        }
        res = max (res, r-l +1);
    }
    if (res == 0 ) cout << -1;
    else cout << res;
}