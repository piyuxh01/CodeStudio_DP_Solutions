int solve(vector<int>& houses,int i,vector<int>&dp){
	if(i == 0){
		return houses[0];
	}
	if(i < 0){
		return 0;
	}
	if(dp[i] != -1){
		return dp[i];
	}
	return dp[i] = max(solve(houses,i-2,dp)+houses[i],solve(houses,i-1,dp));
}
int maxMoneyLooted(vector<int> &houses, int n)
{
	vector<int> dp(n+1,-1);
	return solve(houses,n-1,dp);
	/*
		Write your code here.
		Don't write main().
	 	Don't take input, it is passed as function argument.
	 	Don't print output.
	 	Taking input and printing output is handled automatically.
	*/
}
