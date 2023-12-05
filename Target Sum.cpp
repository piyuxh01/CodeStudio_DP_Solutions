#include <bits/stdc++.h> 
int cnt(vector<int>& arr,int n,int target){
    vector<int> dp(target+1,0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=target;j>=0;j--){
            if(j - arr[i-1] >= 0){
                dp[j] += dp[j-arr[i-1]];
            }
        }
    }
    return dp[target];
}
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    target += accumulate(arr.begin(),arr.end(),0);
    if(target%2 || target < 0) return 0;
    return cnt(arr,n,target/2);
}
