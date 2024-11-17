#include <bits/stdc++.h>
using namespace std;

int t;
int n,c;
int a[100001];

bool check ( int dis ){
    int last = a[0];
    int count = 1;
    for (int i = 1 ; i < n ; i++){
        if (a[i] - dis >= last ){
            last = a[i];
            count ++;
        }
    }
    if ( count  >= c ) return true;
    else return false;
}

int main(){
    //freopen("MaxDistanceSubSequence.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> c;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        
        int left = 0;
        int right = a[n-1]-a[0];
        int res = 0 ;
        while (left <= right){
            int mid = left + (right - left) /2 ;
            if (check(mid)){
                res = mid ;
                left = mid +1;
            }
            else right = mid -1 ;
        }
        cout << res << endl;
    }

    return 0;
}