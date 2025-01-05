#include <bits/stdc++.h>
using namespace std;
struct khobau{
    int x,y,w;
};
khobau p[1001];
int dp[1001];
int n;

bool cmp(khobau p1,khobau p2){
    if (p1.x == p2.x ) return p1.y < p2.y;
    return p1.x < p2.x;
}
int main(){
    cin >> n;
    for (int i = 1; i<= n; i++){
        cin >> p[i].x >> p[i].y >> p[i].w;
    }
    sort(p+1,p+n+1,cmp);
    dp[0]=0;
    for (int i = 1; i<= n; i++){
        for (int j = 1; j< i; j++){
            dp[i] = max (dp[i], dp[j] + p[i].w);
        }
    }
    cout << dp[n];

}