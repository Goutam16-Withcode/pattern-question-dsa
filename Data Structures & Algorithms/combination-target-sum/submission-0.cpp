class Solution {
public:
    vector<vector<int>>ans;
    void solve(int start,int target,vector<int>&curr,vector<int>&nums){
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        if(target<0) return ;
        for(int i=start;i<nums.size();i++){
            curr.push_back(nums[i]);
            solve(i,target-nums[i],curr,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        solve(0,target,curr,nums);
        return ans;
    }
};
