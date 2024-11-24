#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1000005];
int res = 0;
int i,j;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("test.inp","r",stdin);
    cin >>n >>m;
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    i=1; j = n;
    while (i<j){
        if (a[i] + a[j] == m){
            res++;
            i++;
            j--;
        }
        else if (a[i] + a[j] < m){
            i++;
        }
        else j--;
    }
    cout << res;
}