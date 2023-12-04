#include <bits/stdc++.h> 
int solve(string& s,string& t,int i,int j,vector<vector<int>>&dp){
    if(i == s.size() or j == s.size()){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s[i] == t[j]){
        return dp[i][j] = 1 + solve(s,t,i+1,j+1,dp);
    }
    else{
        return dp[i][j] = max(solve(s,t,i+1,j,dp),solve(s,t,i,j+1,dp));
    }
}
int longestPalindromeSubsequence(string s)
{
    vector<vector<int>> dp(s.size()+1,vector<int>(s.size(),-1));
    string t = s;
    reverse(begin(t),end(t));
    return solve(s,t,0,0,dp);
    // Write your code here.
}
