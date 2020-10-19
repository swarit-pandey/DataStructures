/*
PROBLEM STATEMENT:
Given a 2-d array matrix, return elements in spiral order starting from matrix[0][0].

Constraints

    Number of rows in matrix is at most 200.
    Number of columns in matrix is at most 200.

Example 1

Input

matrix = [
    [6, 9, 8],
    [1, 8, 0],
    [5, 1, 2],
    [8, 0, 3],
    [1, 6, 4],
    [8, 8, 10]
]

Output

[6, 9, 8, 0, 2, 3, 4, 10, 8, 8, 1, 8, 5, 1, 8, 1, 0, 6]


*/


class Solution {
    public:
    vector<int> solve(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        int left = 0;
        int dir = 0;
        int i = 0;
        vector<int> res;
        
        while(top <= bottom and left <= right) {
            if(dir == 0) {
                for(i = left; i <= right; ++i) {
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir == 1) {
                for(i = top; i <= bottom; ++i) {
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir == 2) {
                for(i = right; i >= left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else if(dir == 3) {
                for(i = bottom; i >= top; --i) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            dir = (dir + 1) % 4;
        }
        return res;
    }
};
