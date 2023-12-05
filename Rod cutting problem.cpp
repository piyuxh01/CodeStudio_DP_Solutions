int dfs(int i,int n,vector<int> &prices,vector<vector<int>> &dp){
  if(i == 0) return n*prices[0];
  if(dp[i][n] != -1) return dp[i][n];
  int exc = dfs(i-1,n,prices,dp);
  int inc = 0;
  if(n >= i+1){
    inc = dfs(i,n - (i+1),prices,dp) + prices[i];
  }
  return dp[i][n] = max(inc,exc);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
  vector<vector<int>> dp(price.size()+1,vector<int>(n+1,-1));
  int ans = dfs(price.size()-1,n,price,dp);
  return ans;
}
