const int MOD = 1e9+7;
int dfs(int i, int j, vector<vector<int>> &mat,vector<vector<int>> &dp){
    int n = mat.size();
    int m = mat[0].size();
    if(i < 0 or j < 0 or i >= n or j >= m or mat[i][j] == -1) return 0;
    if(i == n-1 and j == m-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = (dfs(i+1,j,mat,dp)%MOD + dfs(i,j+1,mat,dp)%MOD)%MOD;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return dfs(0,0,mat,dp);
}
