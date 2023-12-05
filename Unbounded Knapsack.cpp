#include <bits/stdc++.h>
int dfs(int i, int w, vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp){
    if(i == 0) return (w/weight[0])*profit[0];
    if(dp[i][w] != -1) return dp[i][w];
    int exc = dfs(i-1,w,profit,weight,dp);
    int inc = INT_MIN;
    if(w >= weight[i]){
        inc = dfs(i,w-weight[i],profit,weight,dp) + profit[i];
    }
    return dp[i][w] = max(inc,exc);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    return dfs(n-1,w,profit,weight,dp);
}
