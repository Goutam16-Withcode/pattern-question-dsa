class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int  i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]); // 1 2  3 4 ---> 1 3 2 4
            }
        }
        for(int j=0;j<n;j++){
            reverse(matrix[j].begin(),matrix[j].end());
        }
    }
};
