#include <bits/stdc++.h> 
const int MaxN = 1e9+7;
int dfs(int i,int maxi,int curr,vector<int> &a,vector<vector<int>> &dp){
    if(i >= a.size()){
        if(maxi == curr){
            return 0;
        }
        else{
            return MaxN;
        }
    }
    if(dp[i][curr] != -1) return dp[i][curr];
    int inc = 1 + dfs(i+1,maxi,curr|a[i],a,dp);
    int exc = dfs(i+1,maxi,curr,a,dp);
    return dp[i][curr] = min(inc,exc);
}
int subsetOR(vector<int> &a) {
    //    Write your code here
    int maxi = 0;
    for(int i=0;i<a.size();i++){
        maxi |= a[i];
    }
    vector<vector<int>> dp(a.size()+1,vector<int>(maxi+1,-1));
    return dfs(0,maxi,0,a,dp);
}
