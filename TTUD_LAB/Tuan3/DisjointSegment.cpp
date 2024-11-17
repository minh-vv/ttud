#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> A[100001];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("DisjointSegment.inp","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second;
    }

    
    sort(A, A + n, cmp);

    int last = A[0].second;
    int res = 1; 

    for (int i = 1; i < n; i++) {
        if (A[i].first > last) {
            res++;
            last = A[i].second;
        }
    }

    cout << res << endl;
    return 0;
}