#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int main(){
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(5,-10)); pq.push(make_pair(10,-20)); pq.push(make_pair (100,-1));
    cout << pq.top().first << " " << pq.top().second << endl;

}