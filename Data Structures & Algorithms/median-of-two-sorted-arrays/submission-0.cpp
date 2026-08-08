class Solution {
   public:
    vector<int> mergeAndStore(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> result;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                result.push_back(nums1[i++]);
            } else {
                result.push_back(nums2[j++]);
            }
        }

        while (i < nums1.size()) {
            result.push_back(nums1[i++]);
        }
        while (j < nums2.size()) {
            result.push_back(nums2[j++]);
        }

        return result;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           vector<int>ans = mergeAndStore(nums1,nums2);
           int n = ans.size();
           if (n % 2 == 1) {
            return ans[n / 2];
        } 
        else return (ans[n / 2 - 1] + ans[n / 2]) / 2.0; 
    }
};
