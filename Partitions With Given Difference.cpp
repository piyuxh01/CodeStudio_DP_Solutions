#include <bits/stdc++.h> 
const int MOD = 1e9+7;
int countPartitions(int n, int diff, vector<int> &v) {
    int sum = 0;
 
    // initialize sum
    for (int i = 0; i < n; i++)
        sum += v[i];
    if (diff > sum)
        return 0;
 
    if ((diff + sum) % 2 != 0)
        return 0;
 
    int s2 = (diff + sum) / 2;
 
    // create Dp to store the computations of subproblems
    int dp[s2 + 1];
 
    // initialize Dp with 0
    for (int i = 0; i <= s2; i++)
        dp[i] = 0;
 
    // Base case
    dp[0] = 1;
    // iterating over Dp to get the current
    // value from previous computations
    for (int i = 0; i < n; i++) {
        for (int j = s2; j >= v[i]; j--) {
            dp[j] += dp[j - v[i]];
            dp[j] %= MOD;
        }
    }
 
    // return answer
    return dp[s2];


}


