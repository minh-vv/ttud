#include <bits/stdc++.h>
using namespace std;

int a[10000];
int x[10000];
int t[10000];
int n,m;
int f = 0 ;
int res=0;

void Try(int k){
    for (int v = 1 ; v <= (m - f - (t[n]-t[k]))/ a[k]; v++){
        x[k] = v;
        f += x[k] * a[k];
        if (k==n){
            if (f==m) res++;
        }
        else Try(k+1);
        f -= x[k] *a[k];
    }
}

int main(){
    freopen("integerLinearEquation.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for (int i = 1 ;i<=n;i++){
        cin >> a[i];
        t[i] = t[i-1] + a[i];
    }
    Try(1);
    cout << res;
    return 0;
}


