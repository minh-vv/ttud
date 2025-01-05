#include <bits/stdc++.h>
using namespace std;
int n,x;
set<int> s; 
string cmd;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n;
    for (int i=1; i<= n;i++) {
        cin >> x;
        s.insert(x);
    }
    set <int> :: iterator p;
    cin >> cmd;
    while (cmd != "#"){
        cin >> x;
        p = s.upper_bound(x);
        if (p!= s.end()) {
            cout << *p  << endl;
        }
        else cout << -1 << endl;
        cin >> cmd;
    }
}