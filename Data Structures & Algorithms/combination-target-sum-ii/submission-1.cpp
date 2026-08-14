class Solution {
public:
    vector<vector<int>>ans;
    void solve(int start,int target,vector<int>&curr,vector<int>&candidates){
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        if(target<0) return ;
        for(int i=start;i<candidates.size();i++){
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            curr.push_back(candidates[i]);
            solve(i+1,target-candidates[i],curr,candidates);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
        sort(candidates.begin(), candidates.end());
        solve(0,target,curr,candidates);
        return ans;
    }
};
