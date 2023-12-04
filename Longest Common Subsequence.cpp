#include<vector>
int solve(string& s, string& t,int i,int j,vector<vector<int>>& dp){
	if(i == 0 or j == 0)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	if(s[i-1] == t[j-1])
		return dp[i][j] = 1+solve(s,t,i-1,j-1,dp);
	else
		return dp[i][j] = max(solve(s,t,i-1,j,dp),solve(s,t,i,j-1,dp));
}
int lcs(string s, string t)
{
	vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
	int ans = solve(s,t,s.size(),t.size(),dp);
	return ans;
	//Write your code here
}
