#include <bits/stdc++.h>
using namespace std;
int n,K,Q;
int c[101][101];
int d[101];
int Cmin = 1e9 + 7;
int y[101]; // diem khoi dau
int x[101]; // diem tiep theo
bool visited[101];
int load[101];
int sum,res = 1e9+7;
int nbr = 0, secment = 0;

bool check_X(int v, int k){
    if (v >0 && visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

bool checkY(int v,int k){
    if (v == 0) return true;
    if (visited[v]) return false;
    if (d[v] > Q) return false;
    return true;
}

void Try_X(int s, int k){
    if (s==0){
        if (k < K) Try_X(y[k+1],k+1);
        return;
    }
    for (int v= 0; v<= n;v++ ){
        if (check_X(v,k)){
            x[s] = v;
            visited[v] = true;
            sum += c[s][v];
            load[k] += d[v];
            secment ++;

            if ( v > 0 ){
                if (sum + (n+nbr-secment)* Cmin < res) Try_X(v,k);
            }
            else{
                if (k==K){
                    if (secment == n+nbr) res = min(res,sum);
                }
                else if (sum + (n+nbr-secment)* Cmin < res)
                    Try_X(y[k+1],k+1);
            }
            visited[v] = false;
            sum -= c[s][v];
            load[k] -= d[v];
            secment--;
        }
    }

}

void Try_Y(int k){
    int s = 0;
    if (y[k-1] > 0) s = y[k-1]+1;

    for ( int v = s ; v <= n; v++){
        if (checkY(v,k)){
            y[k] = v;
            visited[v] = true;
            sum += c[0][v];
            load[k]+= d[v];
            secment ++;

            if (k==K) {
                nbr = secment;
                Try_X(y[1],1);
            }
            else Try_Y(k+1);

            visited[v]=false;
            sum -= c[0][v];
            load[k]-=d[v];
            secment--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("test.inp","r",stdin);

    cin >> n >> K >> Q;
    for (int i=1;i<=n;i++){
        cin >> d[i];
    }

    for (int i=0; i<=n;i++){
        for(int j=0;j<=n;j++){
            cin >> c[i][j];
            if ( c[i][j] >0 ) Cmin = min(Cmin,c[i][j]);
        }
    }
    Try_Y(1);
    cout << res;
    return 0;

}
