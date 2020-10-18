// This is solution for a problem asked in binarysearch.com 
// This code only has class solution 
// Strictly not for production purposes

class Solution {
    public:
    bool solve(vector<vector<int>>& matrix) {
        int Row = matrix.size();
        int Column = matrix[0].size();
        
        for(int i = 1; i < Row; ++i) {
            for(int j = 1; j < Column; ++j) {
                if(matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
