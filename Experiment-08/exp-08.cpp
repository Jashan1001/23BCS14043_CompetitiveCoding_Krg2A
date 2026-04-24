#include <bits/stdc++.h>
using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int currMax = 0;

        for (int len = 1; len <= k && i - len >= 0; len++) {
            currMax = max(currMax, arr[i - len]);
            dp[i] = max(dp[i], dp[i - len] + currMax * len);
        }
    }

    return dp[n];
}

int main() {
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;

    cout << maxSumAfterPartitioning(arr, k) << endl; // 84
    return 0;
}