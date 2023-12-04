int solve(int n, vector<int> days, vector<int> cost,int index,vector<int>& dp){
    if(index >= n)
        return 0;
    if(dp[index] != -1)
        return dp[index];
    int day1 = cost[0] + solve(n,days,cost,index+1,dp);

    int i;
    for(i=index;i<n and days[i] < days[index] + 7;i++);
    int day2 = cost[1] + solve(n,days,cost,i,dp);

    for(i=index;i<n and days[i] < days[index] + 30;i++);
    int day3 = cost[2] + solve(n,days,cost,i,dp);
    return dp[index] = min(day1,min(day2,day3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n,-1);
    return solve(n,days,cost,0,dp);
    // Write your code here.
}
