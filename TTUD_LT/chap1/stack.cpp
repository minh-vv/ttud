#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;
    for(int i = 1; i <=5; i++){
        s.push(i);
    }
    cout << s.top();
    s.pop();
    cout << s.top();
}