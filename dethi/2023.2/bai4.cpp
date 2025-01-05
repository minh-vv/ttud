#include <bits/stdc++.h>
using namespace std;
int n;
int p[1001];
int dp[1001];
int main(){
    freopen("test.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i<= n ; i++){
       cin >> p[i]; 
    }
    dp[0]=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], p[j] + dp[i - j]);
        }
    }  
    cout << dp[n];
}