class Solution {
   public:
    bool possible(vector<int>& piles, int h, int speed) {
        long long hours = 0;
        for (int banana : piles) {
            hours += (banana + speed - 1) / speed;
            if (hours > h) {
                return false;
            }
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(piles , h , mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
