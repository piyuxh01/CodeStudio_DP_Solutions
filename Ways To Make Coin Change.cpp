#include <iostream>
#include <vector>
long dfs(int i,int n,int x,int *denominations,vector<vector<long>> &dp){
    if(x == 0) return 1;
    if(i >= n or x < 0) return 0;
    if(dp[i][x] != -1) return dp[i][x];
    return dp[i][x] = dfs(i+1,n,x,denominations,dp)+dfs(i,n,x-denominations[i],denominations,dp);
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n+1,vector<long>(value+1,-1));
    return dfs(0,n,value,denominations,dp);
}
