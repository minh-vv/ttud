#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000001];
long long s = 0;
long long res = 0;
long long min0 = 0;
long long min1 = 0;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("MES.inp","r",stdin);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i] ;
        s = s + a[i];
        if (s % 2 == 0){
            res = max(res,s-min0);
            min0 = min(s,min0);
        }
        else {
            if (min1 ==0){
                min1 = a[i];
            }
            else {
                res = max(res,s - min1);
                min1 = min(s,min1);
            }
        }
    }
    cout << res ;
    return 0;
}