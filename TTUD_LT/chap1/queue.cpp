#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    for(int i = 1; i <=5; i++){
        q.push(i);
    }
    cout << q.front() ;
    q.pop();
    cout << q.front() ;
}