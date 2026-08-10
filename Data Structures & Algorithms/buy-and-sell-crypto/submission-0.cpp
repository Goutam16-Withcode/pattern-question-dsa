class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int left = 0 , ans = 0;
        for(int i=1;i<n;i++){
            if(prices[i] < prices[left]){
               left = i;
            }
            ans = max(ans,prices[i]-prices[left]);
        }
        return ans;
    }
};
