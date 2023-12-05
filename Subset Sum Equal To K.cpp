#include <bits/stdc++.h> 
int dfs(int i,int k,vector<int> &arr,vector<vector<int>> &dp){
    if(k == 0) return 1;
    if(i == arr.size() or k < 0) return 0;
    if(dp[i][k] != -1) return dp[i][k];
    return dp[i][k] = (dfs(i+1,k-arr[i],arr,dp) + dfs(i+1,k,arr,dp));
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    int ans = dfs(0,k,arr,dp);
    return ans != 0;
}
