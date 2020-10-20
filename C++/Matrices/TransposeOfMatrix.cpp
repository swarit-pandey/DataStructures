/*
Asked on binarysearch.com
Given an integer square (n by n) matrix, return its transpose. A transpose of a matrix switches the row and column indices. That is, for every r and c, matrix[r][c] = matrix[c][r].

For example, given matrix

[1, 2, 3]
[4, 5, 6]
[7, 8, 9]

it becomes

[1, 4, 7]
[2, 5, 8]
[3, 6, 9]

Constraints

    n ≤ 100

Example 1

Input

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

Output

[
    [1, 4, 7],
    [2, 5, 8],
    [3, 6, 9]
]


*/

class Solution {
    public:
    vector<vector<int>> solve(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        vector<vector<int>> ans;
        int Row = matrix.size();
        int Col = matrix[0].size();
        for(int i = 0; i < Row; ++i) {
            vector<int> v;
            for(int j = 0; j < Col; ++j) {
                v.push_back(matrix[j][i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
