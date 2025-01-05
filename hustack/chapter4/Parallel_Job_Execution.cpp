#include <bits/stdc++.h>
using namespace std;
int n;
int d[100001];
int res = -1;
int cmp(int a, int b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n;
    for (int i = 0; i< n; i++){
        cin >> d[i];
    }
    sort(d,d+n,cmp);
    for (int i = 0; i< n; i++){
        res = max(res,d[i]+i);
    }
    cout << res;
}