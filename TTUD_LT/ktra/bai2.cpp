#include <bits/stdc++.h>
using namespace std;

int n, D;
int a[1005];

int main() {
    freopen("test.inp", "r",stdin);
    cin >> n >> D;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int sum = 0, count = 0;
    int left = 1;

    for (int right = 1; right <= n; right++) {
        sum += a[right]; 

        while (sum >= D) { 
            count += (n - right + 1); 
            sum -= a[left];          
            left++;                  
        }
    }

    cout << count;
    return 0;
}
