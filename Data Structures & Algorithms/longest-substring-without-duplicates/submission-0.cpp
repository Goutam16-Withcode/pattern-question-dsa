class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
 
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            // Expand
            freq[s[right]]++;

            // Shrink until window is valid
            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }

            // Update answer
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
