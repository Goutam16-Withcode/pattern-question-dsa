class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> last_seen; // maps value -> index
        
        for (int i = 0; i < nums.size(); i++) {
            // Check if element exists and distance is <= k
            if (last_seen.count(nums[i]) && (i - last_seen[nums[i]] <= k)) {
                return true;
            }
            // Update or insert the latest index of the number
            last_seen[nums[i]] = i;
        }
        
        return false;
    }
};
