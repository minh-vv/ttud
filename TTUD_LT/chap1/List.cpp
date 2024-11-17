#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    list<int> l;
    for (int i = 1; i<=5 ; i++ ) {
        l.push_back(i);
    }
    list<int> :: iterator p;
    p = l.begin();
    advance(p,2);
    cout << *p << endl;
    l.erase(p);
    cout << *p << endl;
    advance(p,-1); // p van tro den 3. phai lui ve
    l.insert(p,2,6); 
    for (p = l.begin(); p != l.end();p++){
        cout << *p << " ";
    }

}
