#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1); v.push_back(2);
    for (int i = 3; i<=10 ; i++ ) v.push_back(i);
    for (int i : v) cout << i << " ";
    cout << endl;
    v.erase(v.begin(), v.begin() +3 );
    for (int i : v) cout << i << " ";
    return 0;
}