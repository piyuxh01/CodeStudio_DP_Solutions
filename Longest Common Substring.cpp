#include <bits/stdc++.h> 
int lcs(string &str1, string &str2){
	int m = str1.length();
	int n = str2.length();
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	int maxi = 0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(str1[i-1] == str2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				maxi = max(maxi,dp[i][j]);
			}
		}
	}
	return maxi;
	//	Write your code here.
}
