#include <bits/stdc++.h>
using namespace std;

int n,m,r,c;
int A[1005][1005];
int visited[1005][1005];
int buoc[1005][1005];
int dx ={0,1,0,-1};
int dy ={1,0,-1,0};
int res = -1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("Maze.inp","r",stdin);
    cin >> n,m,r,c;
    for (int i = 1; i <= n ;i++){
        for (int j= 1; j<=m; j++){
            cin >> A[i][j];
        }
    }
    queue < pair<int,int> > q;
    q.push((r,c));
    visited[r][c] = 1;
    buoc[r][c] = 0;

    while( !q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        for (int i= 0;i<4;i++){
            int vx = u.first + dx[i];
            int vy = u.second + dy[i];
            if (a[vx][vy] ==0 && visited ==0 ){
                visited[vx][vy] = 1;
                d[vx][vy]= d[u.first][u.second] + 1;
                q.push((vx,vy));
                if (vx == 1 || vx == n )

            }
        }
    }
}

