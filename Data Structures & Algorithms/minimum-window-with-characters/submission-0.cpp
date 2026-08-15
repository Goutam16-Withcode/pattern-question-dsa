class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char,int> need, window;
        for (char c : t) need[c]++;

        int required = need.size();   // number of distinct chars in t we must fully satisfy
        int formed = 0;                // number of distinct chars currently satisfied

        int left = 0;
        int bestLen = INT_MAX, bestStart = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            // Try to shrink from the left while window is still valid
            while (left <= right && formed == required) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }

                char lc = s[left];
                window[lc]--;
                if (need.count(lc) && window[lc] < need[lc]) {
                    formed--;
                }
                left++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};