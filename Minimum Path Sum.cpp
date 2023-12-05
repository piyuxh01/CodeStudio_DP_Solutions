#include <bits/stdc++.h> 
int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp){
    int n = grid.size();
    int m = grid[0].size();
    if(i < 0 or j < 0 or j >= m or i >= n) return INT_MAX;
    if(i == n-1 and j == m-1) return grid[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int a = dfs(i+1,j,grid,dp);
    int b = dfs(i,j+1,grid,dp);
    return  dp[i][j] = min(a,b) + grid[i][j];
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans =dfs(0,0,grid,dp);
    return ans;
}
