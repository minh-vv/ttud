#include <bits/stdc++.h>
using namespace std;
int v;
string s;
stack<int> t;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("test.inp","r",stdin);
    cin >> s;
    while (s != "#"){
        if (s == "PUSH"){
            cin >> v;
            t.push(v);
        }
        if (s == "POP" ){
            if(!t.empty()){
                cout << t.top() << endl;
                t.pop();
            }
            else cout << "NULL\n";
            
        }
        cin >> s;
    } 
}