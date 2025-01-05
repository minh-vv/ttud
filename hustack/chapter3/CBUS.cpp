#include <bits/stdc++.h>
using namespace std;
int n,K;
int c[100][100];
int Cmin = 100000;
int visited[100];
int x[100];
int load;
int sum = 0;
int res = 100000;

bool check(int v){
    if (visited[v]) return false;
    if (v > n & visited[v-n] == 0) return false;
    if (v <= n & load >= K ) return false;
    return true;
}

void Try(int k){
    for (int v = 1; v <= 2*n ; v++){
        if (check(v)){
            x[k] = v;
            visited[v] = 1;
            if (v > n ) load--;
            else load ++;
            sum += c[ x[k-1] ][ x[k] ];

            if (k == 2*n){
                res = min(res, sum + c[x[k]][0]);
            }
            else {
                if (sum + Cmin * (2*n-k+1) < res){
                    Try(k+1);
                }
            }
            visited[v] = 0;
            if (v > n ) load++;
            else load --;
            sum -= c[ x[k-1] ][ x[k] ];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test.inp","r",stdin);
    cin >> n >> K;
    for (int i=0; i <= 2*n ; i++){
        for (int j=0 ; j<= 2*n; j++){
            cin >> c[i][j];
            if (c[i][j] > 0 ) Cmin = min(Cmin,c[i][j]);
        }
    }
    Try(1);

    cout << res;
}
