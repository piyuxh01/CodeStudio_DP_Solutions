#include <bits/stdc++.h>
bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}
int findMaxEnvelopes(vector<int> &height, vector<int> &width, int n) {
    vector<pair<int,int>> envelopes;
    for(int i=0;i<n;i++){
        envelopes.push_back(make_pair(height[i],width[i]));
    }
    sort(envelopes.begin(), envelopes.end(),cmp);
    vector<int> dp;
    dp.push_back(envelopes[0].second);
    for (int i = 1; i < n; ++i) {
        if (envelopes[i].second > dp.back())
            dp.push_back(envelopes[i].second);
        else{
            int index = lower_bound(dp.begin(),dp.end(),envelopes[i].second) - dp.begin();
            dp[index] = envelopes[i].second;
        }
    }
    return dp.size();
    // Write your code here.
}
