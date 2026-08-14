class Solution {
public:
    bool dfs(int r, int c, int idx, string& word, vector<vector<char>>& board) {
        // If we matched all characters in the word
        if (idx == word.size()) return true;
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Check bounds and character match
        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[idx]) 
            return false;
        
        // Mark as visited
        char temp = board[r][c];
        board[r][c] = '#';
        
        // Recurse in all 4 directions with idx + 1
        bool found = dfs(r - 1, c, idx + 1, word, board) || 
                     dfs(r + 1, c, idx + 1, word, board) || 
                     dfs(r, c - 1, idx + 1, word, board) || 
                     dfs(r, c + 1, idx + 1, word, board);
        
        // Restore character
        board[r][c] = temp;
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If DFS finds the word starting from (i, j), return true
                if (dfs(i, j, 0, word, board)) 
                    return true;
            }
        }
        return false;
    }
};
