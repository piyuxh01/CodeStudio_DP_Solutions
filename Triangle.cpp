#include <bits/stdc++.h> 
int dfs(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
	int n = triangle.size();
	if(dp[i][j] != -1) return dp[i][j];
	if(i == n-1) return triangle[i][j];
	return dp[i][j] = min(dfs(i+1,j,triangle,dp),dfs(i+1,j+1,triangle,dp)) + triangle[i][j];
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(n,vector<int>(n,-1));
	return dfs(0,0,triangle,dp);
}
