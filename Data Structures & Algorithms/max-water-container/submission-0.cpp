class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = 0;
        for(int i=0;i<h.size();i++){
            for(int j=h.size()-1;j>=0;j--){
                int weight = j - i;
                int area = min(h[i],h[j]) * weight;
                ans = max(ans,area);
            }
        }
        return ans;
    }
};
