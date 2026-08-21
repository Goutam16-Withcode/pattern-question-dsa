class Solution {
   public:
    bool possible(vector<int>& weights, int mid, int days) {
        int day = 1;
        int load = 0;

        for (int w : weights) {
            if (load + w > mid) {
                day++;
                load = 0;
            }

            load += w;
        }

        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(weights, mid, days)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};