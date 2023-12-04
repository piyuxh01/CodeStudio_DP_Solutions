
int solve(vector<vector<int>>& MAT,int i,int j,vector<vector<int>>& dp,int& maxi){
    if(i >= MAT.size() or j >= MAT[0].size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int left = solve(MAT,i+1,j,dp,maxi);
    int right = solve(MAT,i,j+1,dp,maxi);
    int diag = solve(MAT,i+1,j+1,dp,maxi);
    if(MAT[i][j] == 1){
        dp[i][j] = 1 + min(left,min(right,diag));
        maxi = max(maxi,dp[i][j]);
        return dp[i][j];
    }
    else 
        return dp[i][j] = 0;
}

int maximumAreaSquare(vector<vector<int>>& MAT, int n, int m)
{
    int maxi = 0;
    vector<vector<int>>dp(MAT.size(),vector<int>(MAT[0].size(),-1));
    solve(MAT,0,0,dp,maxi);
    return maxi*maxi;
    // Write your code here.
}
