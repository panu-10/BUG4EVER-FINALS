#include<bits/stdc++.h>
using namespace std;

int f(int rem, int chance, vector<vector<int>>& dp) {
    if (rem == 0) {
        if (chance == 0) {
            return 1;
        }
        return 0;
    }
    if (dp[rem][chance] != -1) return dp[rem][chance];
    int min1 = INT_MAX;
    int max1 = INT_MIN; 
    for (int i = 1; i * i <= rem; i++) {
        int ans = f(rem - (i * i), chance ^ 1, dp); 
        if (chance == 0) {
            min1 = min(min1, ans);
        }
        else {
            max1 = max(max1, ans);
        }
    }
    if (chance == 0) {
        dp[rem][chance] = min1;
    }
    else {
        dp[rem][chance] = max1;
    }
    return dp[rem][chance];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        cout << f(n, 1, dp) << endl;
    }
    return 0;
}