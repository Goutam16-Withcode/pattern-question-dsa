class Solution {
   public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& used, vector<int>& curr) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            curr.push_back(nums[i]);
            solve(nums, used, curr);
            curr.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
        vector<int> curr;
        solve(nums, used, curr);
        return ans;
    }
};
