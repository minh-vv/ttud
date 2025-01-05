#include <bits/stdc++.h>
using namespace std;
int n;
int c[1001][1001];
vector<int> x;
bool visited[1001];
int mincity = 1000000;
int city = 0;
void thamlam(){
    int nowcity = city;
    visited[nowcity] = true;
    x.push_back(nowcity);

    for (int k=2;k<=n;k++){
        int min = 10000000;
        int nextcity = -1;

        for (int i = 1; i<=n; i++){
            if (!visited[i] && c[nowcity][i] < min){
                min = c[nowcity][i];
                nextcity = i;
            } 
        }
        x.push_back(nextcity);
        visited[nextcity] = true;
        nowcity = nextcity;
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n ;
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j] ;
            if (mincity > c[i][j]) {
                mincity = c[i][j];
                city = i;
            }
        }
    }
    thamlam();
    cout << n << endl;
    for (int i = 0; i < n; i++){
        cout << x[i] << " " ;
    }

}

