#include <bits/stdc++.h> 
long long robber(vector<int>& nums, long long l, long long r) {
        long long pre = 0, cur = 0;
        for (long long i = l; i <= r; i++) {
            long long temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
      
    }
long long int houseRobber(vector<int>& nums)
{
    long long n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
}
