class Solution {
   public:
    int characterReplacement(string s, int k) {
        int ans = 0, left = 0, maxfreq = 0;
        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;

            maxfreq = max(maxfreq, mp[s[i]]);

            while (i - left + 1 - maxfreq > k) {
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
