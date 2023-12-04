#include <bits/stdc++.h>
int solve(vector<int>& num,int tar,vector<int>& dp){
    if(tar == 0)
        return 1;
    if(tar < 0){
        return 0;
    }
    if(dp[tar] != -1)
        return dp[tar];
    int ans = 0;
    for(int i=0;i<num.size();i++){
        ans += solve(num,tar - num[i],dp);
    }
    return dp[tar] = ans;
}
int findWays(vector<int> &num, int tar)
{
    vector<int> dp(num.size(),-1);
    return solve(num,num.size()-1,dp);
    // Write your code here.
}
