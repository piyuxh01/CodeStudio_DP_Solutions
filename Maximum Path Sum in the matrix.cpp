#include <bits/stdc++.h> 
const int NEG=INT_MIN;
int dfs(int i,int j,int n,int m,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    if(j >= m || j < 0) return NEG;
    if(i == n-1) return matrix[i][j];
    if(dp[i][j] != NEG) return dp[i][j];
    int dn = dfs(i+1,j,n,m,matrix,dp);
    int dl = dfs(i+1,j+1,n,m,matrix,dp);
    int dr = dfs(i+1,j-1,n,m,matrix,dp);
    return dp[i][j] = max(dn,max(dl,dr)) + matrix[i][j];
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,NEG));
    int ans = NEG;
    for(int j=0;j<m;j++){
        int x = dfs(0,j,n,m,matrix,dp);
        ans = max(ans,x);
    }
    return ans;
    //  Write your code here.
}
