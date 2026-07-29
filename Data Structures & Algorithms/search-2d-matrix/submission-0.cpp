class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int n = m.size();
        int l = m[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<l;j++){
                if(m[i][j]==target) 
                  return  true;
            }
        }
        return false;
    }
};
