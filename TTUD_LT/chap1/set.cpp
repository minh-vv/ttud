#include <bits/stdc++.h>
using namespace std;

int main(){
    set <string> s;
    s.insert("abc");
    s.insert("def");
    s.insert("xyz");
    s.insert("xyz");

    set<string> ::iterator p;
    for (p = s.begin(); p != s.end(); p++) {
        cout << *p << endl;
    }
}