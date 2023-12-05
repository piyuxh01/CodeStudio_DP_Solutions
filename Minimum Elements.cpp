#include <bits/stdc++.h> 
int solveRec(vector<int> &num, int x ,vector<int> &dp) {
    // base case
    if( x == 0)
        return 0;
    
    if( x < 0 )
        return INT_MAX;
    if(dp[x] != -1) return dp[x];
    int mini = INT_MAX;
    for( int i = 0; i<num.size(); i++ ) {
        int ans = solveRec( num, x-num[i],dp);
        if( ans != INT_MAX )
            mini = min( mini, 1+ans );
    }
    return dp[x] = mini;
}
int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1,-1);
    int ans = solveRec(num,x,dp);
    if(ans == INT_MAX) ans = -1;
    return ans;
    // Write your code here.
}
