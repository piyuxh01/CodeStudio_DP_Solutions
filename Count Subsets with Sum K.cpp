const int MOD = 1e9+7;
int dfs(int i,int sum,vector<int>& arr,vector<vector<int>> &dp){
	if(sum == 0) return 1;
	if(i >= arr.size() or sum < 0) return 0;
	if(dp[i][sum] != -1) return dp[i][sum];
	return dp[i][sum] = (dfs(i+1,sum-arr[i],arr,dp)%MOD + dfs(i+1,sum,arr,dp)%MOD)%MOD;
}
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
	int ans =  dfs(0,k,arr,dp);
	return ans;
	// Write your code here.
}
