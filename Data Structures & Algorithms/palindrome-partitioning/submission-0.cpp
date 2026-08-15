class Solution {
private:
    vector<vector<string>> ans;

    bool isPalindrome(const string& s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--])
                return false;
        }
        return true;
    }

public:
    void solve(int start, string& s, vector<string>& curr) {
        if (start == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (!isPalindrome(s, start, end))
                continue;
            curr.push_back(s.substr(start, end - start + 1));
            solve(end + 1, s, curr);
            curr.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        ans.clear(); // Clear any previous results if the instance is reused
        vector<string> curr;
        solve(0, s, curr);
        return ans;
    }
};
