class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        long long prefix  = 0 ;
        int ans = 0;
        for(int c : nums){
            prefix+=c;

            if(mp.count(prefix-k)){
                ans+=mp[prefix-k];
            }
            mp[prefix]++;
        }
        return ans;
    }
};