#include <bits/stdc++.h>
int MOD = 1e9+7;
int solve(int i,int n,vector<int>& dp){
    if(i == n){
        return 1;
    }
    if(i > n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    return dp[i] = (solve(i+1,n,dp)%MOD + solve(i+2,n,dp)%MOD)%MOD;
}
int countDistinctWays(int nStairs) {
    vector<int> dp(nStairs,-1);
    return solve(0,nStairs,dp);
    //  Write your code here.
}
