int lcs(int i,int j,string &str,string &rstr,vector<vector<int>> &dp){
	if(i == 0 or j == 0) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(str[i-1] == rstr[j-1]) return dp[i][j] = 1 + lcs(i-1,j-1,str,rstr,dp);
	else{
		return dp[i][j] = max(lcs(i,j-1,str,rstr,dp),lcs(i-1,j,str,rstr,dp));
	}
}
int minimumInsertions(string &str)
{
	int n = str.size();
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	string rstr = str;
	reverse(begin(rstr),end(rstr));
	return n - lcs(n,n,str,rstr,dp);
	// Write your code here.
}
