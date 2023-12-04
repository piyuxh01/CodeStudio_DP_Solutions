#include <bits/stdc++.h>
int solve(vector<int>& nums,int n,vector<int>& dp){
    if(n < 0 ) 
        return 0;
    if(n == 0)
        return nums[0];
    if(dp[n] != -1)
        return dp[n];
    int inc = solve(nums,n-2,dp) + nums[n];
    int exc = solve(nums,n-1,dp);
    return dp[n] = max(inc,exc);
} 
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size()+1,-1);
    return solve(nums,nums.size()-1,dp);
    // Write your code here.
}
