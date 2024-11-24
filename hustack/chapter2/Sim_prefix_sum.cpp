#include <bits/stdc++.h>
using namespace std;
int n,q,x;
int a[1000001];
int sum;
int i,j;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++) {
        cin >> x;
        a[i] = a[i-1] + x;
    }
    cin >> q;
    for (int k = 1; k <= q; k++){
        cin >> i >> j;
        cout << a[j] - a[i-1] << endl;
    }
}