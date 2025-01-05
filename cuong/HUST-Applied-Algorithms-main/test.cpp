#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[104];
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a+n);

    int m; cin >> m;
    vector<int> dp(sum, 0);

    dp[0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = sum; j >= a[i]; j--){
            if (dp[ j - a[i] ] == 1){
                dp[j] = 1;
            }
        }
    }

    for (int j = m; j >= 0; j--){
        if (dp[j]){
            cout << m - j;
            return 0;
        }
    }
}
