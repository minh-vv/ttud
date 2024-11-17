#include<bits/stdc++.h>
using namespace std;
long long n,l1,l2;
long long a[1000001];
long long f[1000001];
deque <long> dq;
long long res;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> l1 >> l2;
    for (int i = 1 ;i<= n ;i++){
        cin >> a[i];
        if (i > l1){
            while (!dq.empty() && f[dq.back()] < f[i-l1])
                dq.pop_back();
            while (!dq.empty() && dq.front() < i - l2)
                dq.pop_front();
            dq.push_back(i-l1);
            f[i] = f[dq.front()] + a[i];
        }
        else {
            f[i] = a[i];
        }
        res = max (res, f[i]);
    }
    cout << res;
    return 0;

}