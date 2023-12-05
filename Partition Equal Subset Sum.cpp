int dfs(int i,int x,vector<int> &arr,vector<vector<int>> &dp){
	if(x == 0) return 1;
	if(x < 0 or i >= arr.size()) return 0;
	if(dp[i][x] != -1) return dp[i][x];
	return dp[i][x] = dfs(i+1,x - arr[i],arr,dp) + dfs(i+1,x,arr,dp);
}
bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(auto i:arr) sum+=i;
	if(sum%2 == 1) return 0;
	int k = sum/2;
	vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
	return dfs(0,k,arr,dp) != 0;
	// Write your code here.
}
