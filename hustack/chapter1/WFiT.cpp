#include <bits/stdc++.h>
using namespace std;
string cmd;
map<string, int> m;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    while (getline(cin,cmd)){
        int begin = 0;
        string tmp;
        for (int i=0 ; i< cmd.size() ; i++){
            if (!isalpha(cmd[i]) && !isdigit(cmd[i])){
                if (begin != i) {
                    tmp = cmd.substr(begin, i-begin +1);
                    m[tmp]++;
                }
                begin = i + 1;
            }
        }
    }
    for (pair<string,int> p : m){
        cout << p.first << " " << p.second << endl;
    }

}