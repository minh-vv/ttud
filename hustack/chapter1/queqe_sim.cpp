#include <bits/stdc++.h>
using namespace std;
int v;
string s;
queue<int> q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("test.inp","r",stdin);
    cin >> s;
    while (s != "#"){
        if (s == "PUSH"){
            cin >> v;
            q.push(v);
        }
        if (s == "POP" ){
            if(!q.empty()){
                cout << q.front()<< endl;
                q.pop();
            }
            else cout << "NULL\n";
            
        }
        cin >> s;
    } 
}