class Solution {
public:
    vector<vector<int>>ans;
    void subset(int idx , vector<int>&nums,vector<int>&curr){
        if(idx==nums.size()){
            ans.push_back(curr);
            return ;
        }
        curr.push_back(nums[idx]);
        subset(idx+1,nums,curr);
        curr.pop_back();
        subset(idx+1,nums,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        int n = nums.size();
        subset(0,nums,curr);
        return ans;
    }
};
