class Solution {
   public:
    int reverse(int x) {
        int resversenum = 0;
        while (x != 0) {
            int lastD = x % 10;
            if (resversenum > INT_MAX / 10 || resversenum < INT_MIN / 10) {
                return 0;
            }
            resversenum = (resversenum * 10) + lastD;
            x /= 10;
        }
        return resversenum;
    }
};
