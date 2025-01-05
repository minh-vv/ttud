#include <bits/stdc++.h>

using namespace std;

vector<int> dp;
void solve(vector<int> nums) {
    dp[0] = 1;  

    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = 1;  
        for (int j = 0; j < i; ++j) {
            if ((nums[i] % 2 == 0 && nums[j] % 2 == 0 && nums[i] > nums[j]) || (nums[i] % 2 != 0 && nums[j] % 2 != 0 && nums[i] > nums[j])) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
}

int main() {
    freopen("test.inp", "r",stdin);
    int n;
    cin >> n;  
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i]; 
    }

    dp.resize(n, 0);  
    solve(nums); 

    cout << *max_element(dp.begin(), dp.end());  
    return 0;
}