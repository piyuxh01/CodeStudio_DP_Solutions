int dfs(int i,int sum,int k,vector<int> &arr,vector<vector<int>> &dp){
	if(i == arr.size() - 1){
		return abs((sum - k ) - k);
	}
	if(dp[i][k] != -1) return dp[i][k];
	return dp[i][k] = min(dfs(i+1,sum,k+arr[i],arr,dp),dfs(i+1,sum,k,arr,dp));
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += arr[i];
	}
	vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
	int ans = dfs(0,sum,0,arr,dp);
	return ans;
	// Write your code here.
}
