#include <bits/stdc++.h>
using namespace std;
vector <int> kh[100]; // kh i duoc giao vien k day
vector <int> gv[100]; // gv k dang day  kh i
int n,m;
int trungGio[100][100];
int res= 1000;
int load[100];

bool check(int g, int k){
    for (int i: gv[g]){
        if (trungGio[i][k] == 1) return false;
    }
    return true;
}

void Try(int k){
    for (int g : kh[k]){
        if (check(g,k)){
            gv[g].push_back(k);
            load[g]++;

            if (k == n){
                int maxLoad=0;
                for (int i = 1; i<=m ;i++ ){
                    maxLoad = max(maxLoad,load[i]);
                }
                res = min (maxLoad,res);
            }else{
                if (load[g]<res) Try(k+1);
            }
            load[g]--;
            gv[g].pop_back();
        }
    }
}

int main(){
       freopen("test.inp", "r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 1 ; i<=m; i++){
        int k ;
        cin >> k ;
        for (int j = 1; j<= k ;j++){
            int u ;
            cin >> u;
            kh[u].push_back(i);
        }
    }
    int h ;
    cin >>h;
    for (int i = 1 ; i <= h;i++){
        int x,y;
        cin >> x >> y;
        trungGio[x][y] = trungGio[y][x] = 1;
    }
    memset(load, 0, sizeof(load));
    Try(1);
    if (res!= 1000) cout << res;
    else cout << -1;

    return 0;
}
