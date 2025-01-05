#include <bits/stdc++.h>
using namespace std;
int n;
int c[21][21];
int mem[21][1<<21];

int TSP(int i, int s){
    if (s == (1<<n)-1) return mem[i][s] = c[i][0] ;
    if (mem[i][s] != -1) return mem[i][s];
    int res = 1e9;
    for (int j = 0; j <n; j++){
        if (s & (1<<j)) continue;
        res = min(res, c[i][j] +  TSP(j, s | (1<<j)));
    }
    return mem[i][s] = res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    //freopen("test.inp", "r", stdin);
    cin >> n;
    for (int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> c[i][j];
        }
    }
    memset(mem, -1, sizeof(mem));
    cout << TSP(0,1);
}