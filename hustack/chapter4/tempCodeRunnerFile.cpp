#include <bits/stdc++.h>
using namespace std;
pair <int,int> p[100001];
int n;
int d[100001];
int res = 0;
int cmp(pair<int,int> p1, pair<int,int> p2){
    return p1.second > p2.second;

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n;
    for (int i = 1;i<=n;i++) {
        cin >> p[i].first >> p[i].second;
       
    }
    sort(p+1,p+n+1,cmp);
    for(int i = 1;i<=n;i++) {
        if (d[p[i].first] == 0) {
            res += p[i].second;
            d[p[i].first] =1;
        }
    }
    cout << res;
}