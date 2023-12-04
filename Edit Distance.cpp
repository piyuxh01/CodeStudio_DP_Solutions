
int solve(string& str1, string& str2,int i,int j,vector<vector<int>>& dp){
    if(i == str1.size()){
        return str2.size() - j;
    }
    if(j == str2.size()){
        return str1.size() - i;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(str1[i] == str2[j]){
        return dp[i][j] = solve(str1,str2,i+1,j+1,dp);
    }
    else{
        return dp[i][j] = 1 + min(solve(str1,str2,i+1,j+1,dp),min(solve(str1,str2,i+1,j,dp),solve(str1,str2,i,j+1,dp)));
    }
}
int editDistance(string str1, string str2)
{
    vector<vector<int>> dp(str1.size(),vector<int>(str2.size(),-1));
    return solve(str1,str2,0,0,dp);
    //write you code here
}
