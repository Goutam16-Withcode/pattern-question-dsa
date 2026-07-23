class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        for(auto c : nums){
            if(s.count(c)) return true;
            s.insert(c);
        }
        return false;
    }
};