#include <bits/stdc++.h>
using namespace std;

const int MAX_NOTE = 1e5+1;
const int MAX_EG = 1e6+1;
int sonut, socanh;
vector<int> dothi[MAX_NOTE];
vector<int> dothidao[MAX_NOTE];
stack<int> stackNode;
bool visited[MAX_NOTE];
int res = 0;
void dfs1(int u){
    visited[u] = true;
    for (int v : dothi[u]){
        if (!visited[v]){
            dfs1(v);
        }
    }
    stackNode.push(u);
}
void dfs2(int u){
    visited[u] = true;
    for (int v : dothidao[u]){
        if (!visited[v]){
            dfs2(v);
        }
    }
}
void solve(){
    for (int i=1; i <= sonut; i++){
        if (!visited[i]){
            dfs1(i);
        }
    }
    memset(visited,false,sizeof(visited));
    while (!stackNode.empty()){
        int u = stackNode.top();
        stackNode.pop();
        if (!visited[u]){
            res++;
            dfs2(u);
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> sonut >> socanh;
    int u,v;
    for (int i = 0; i< socanh; i++) {
        cin >> u >> v;
        dothi[u].push_back(v);
        dothidao[v].push_back(u);
    }    
    memset(visited,false,sizeof(visited));
    solve();
    cout << res;
}