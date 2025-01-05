#include <bits/stdc++.h>
using namespace std;
int n1,n2,l,m,p,u,v;
int a[10001];
int c[10001][10001];
int d[10001];
vector<int> visited;
int maxCophieu ;
int res = -1;
bool check(){
    if (visited.size() > l) return false;
    int count1 =0;
    int count2 = 0;

    for (int i : visited){
        if (i <= n1) count1 ++;
        else count2 ++;
    }
    if (count1 < m || count2 < m) return false;
  
    for (int i : visited){
        for (int j : visited) {
            if(c[i][j]) return false;
        }
    }
    return true;
}

int kq(){
    int sum = 0;
    for (int v : visited) {
        sum += d[v];
    }
    return sum;
}

void Try(int k){
    if (k == maxCophieu) {
        if (check()){
            res = max(res,kq());
        }
        return;
    }
    Try(k+1);

    visited.push_back(k);
    Try(k+1);
    visited.pop_back();
    
}
    

int main(){
    freopen("test.inp","r",stdin);
    cin >> n1 >> n2;
    for (int i =1; i <=n1+n2; i++){
        cin >> d[i];
    }
    cin >> l >> m >> p;
    memset(c, 0, sizeof(c));
    for (int i = 0; i<p; i++){
        cin >> u >> v;
        c[u][v] = c[v][u] =1;
    }
    maxCophieu = n1+n2;
    Try(1);
    cout << res;
}