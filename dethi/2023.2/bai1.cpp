#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int minR = 1e9;
    int maxR = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        minR = min(minR, a[i]);
        maxR = max(maxR, a[i]);
    }
    cout << maxR << " " << minR << endl;
    
}