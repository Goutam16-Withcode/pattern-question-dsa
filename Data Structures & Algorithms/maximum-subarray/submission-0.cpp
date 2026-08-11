class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       long long sum = 0 , minsum = 0;
       long long ans = LLONG_MIN;
       for(int x : nums){
           sum += x;
           ans = max(ans,sum-minsum);
           minsum = min(minsum,sum);
       }
       return ans;
    }
};
