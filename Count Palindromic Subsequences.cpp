#include <bits/stdc++.h> 
int mod = 1e9+7;
int countPalindromicSubseq(string &s)
{
	int n=s.size();
    int dp[n][n];
    
    for( int i=n-1;i>=0;i--)
    {
        for( int j=0;j<n;j++)
        {
            if(i>j)
            {
                dp[i][j]=0;
            }
            else if(i==j)
            {
                dp[i][j]=1;
            }
            else
            {
                if(s[i]==s[j])
                {
                    dp[i][j] = (1+dp[i+1][j]+dp[i][j-1])%mod;
                }
                else
                {
                    dp[i][j] = (dp[i+1][j] +dp[i][j-1] -dp[i+1][j-1])%mod;
                }
            }
        }
       
    }
    return dp[0][n-1];
	//    Write your code here.
}
