#include <bits/stdc++.h>
using namespace std;


int main(){
    map <string,int> m;
    m["abc"] = 1;
    m["def"] = 2;
    m["xyz"] = 3;
    cout << m["xyz"] << endl;
    for (map <string,int>::iterator p = m.begin(); p != m.end();p++){
        cout << p->first << " " << p->second << endl;
    }
}