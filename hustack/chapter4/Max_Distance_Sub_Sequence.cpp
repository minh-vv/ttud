#include <bits/stdc++.h>

using namespace std;

int n,t,c;
int a[1000001];

bool check(int dis){
    int i = 1;
    int count = 1;
    for (int k = i+1 ; k<= n ; k++){
        if (a[k] - a[i] >= dis){
            count ++; 
            i = k;
        }
    }
    if (count >= c) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    //freopen("test.inp", "r", stdin);
    cin >> t;
    while (t--){
        cin >> n >> c;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        int l = 1;
        int r = a[n]-a[1];
        int res = 0;
        while (l<=r){
            int dis = (l+r)/2;
            if (check(dis)){
                res = dis;
                l = dis+1;
            }
            else {
                r = dis-1;
            }
        }
        cout << res << endl;
    }

}