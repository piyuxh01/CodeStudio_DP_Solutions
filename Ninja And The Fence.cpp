#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}
int multiply(int a,int b){
    return ((a%MOD)*1LL * (b%MOD))%MOD;
}
int solve(int n,int k,vector<int>& dp){
    if(n == 1) 
        return k;
    if(n == 2)
        return add(k,multiply(k,(k-1)));
    if(dp[n] != -1)
        return dp[n];
    dp[n] = add(multiply(solve(n-2,k,dp),k-1),multiply(solve(n-1,k,dp),k-1));
    
    return dp[n];
}
int numberOfWays(int n, int k) {
    vector<int> dp(n+1,-1);
    // Write your code here.
    return solve(n,k,dp);
}
