#include<bits/stdc++.h>
using namespace std;

int n;
int x;
set <int> s;
string cmd;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n ;
    for (int i =1; i<=n; i++) {
        cin >> x;
        s.insert(x);
    }
    cin >> cmd;
    
    set<int> :: iterator p;
    while (cmd !="#"){
        cin >> x;
        
        if (cmd == "insert"){
            s.insert(x);
        }
        else if(cmd == "remove"){
            s.erase(x);
        }
        else {
            if (cmd == "min_greater_equal"){
                p = s.lower_bound(x);
            }
            else if (cmd == "min_greater"){
                p = s.upper_bound(x);
            }
            if (p != s.end()) cout <<*p << endl;
            else cout << "NULL\n";
        }
        cin >> cmd;
    }
}