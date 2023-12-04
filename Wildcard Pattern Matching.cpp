#include<vector>
bool solve(string& text, string& pattern,int i, int j, vector<vector<int>>& dp){
   if(i<0 and j<0){
      return true;
   }
   if(i>=0 and j<0){
      return false;
   }
   if(i<0 and j>=0){
      for(int k=0;k<=j;k++){
         if(pattern[k] != '*'){
            return false;
         }
      }
      return true;
   }
   if(dp[i][j] != -1){
      return dp[i][j];
   }
   if(text[i] == pattern[j] or pattern[j] == '?' ){
      dp[i][j] = solve(text,pattern,i-1,j-1,dp);
   }
   else if(pattern[j] == '*'){
      dp[i][j] = solve(text,pattern,i-1,j,dp) or solve(text,pattern,i,j-1,dp);
   }
   else{
      return false;
   }
}
bool wildcardMatching(string pattern, string text)
{
   vector<vector<int>> dp(text.size()+1,vector<int>(pattern.size()+1,-1));
   return solve(text,pattern,text.size()-1,pattern.size()-1,dp);
   // Write your code here.
}
