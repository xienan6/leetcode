// Source : https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k
// Author : Nan
// Date   : 2019-11-08
// Runtime: 392 ms

/*
* https://www.youtube.com/watch?v=yCQN096CwWM
*
* Time complexity O(col * col * row * log(row)), Space complexity O(row)
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int row = matrix.size(), col = matrix[0].size(), maxSum = INT_MIN;
        for (int l = 0; l < col; ++l) {
            vector<int> sums(row, 0);
            for (int r = l; r < col; ++r) {
                int currMax = INT_MIN, currSum = 0;
                set<int> accuSet;
                accuSet.insert(0);
                for (int i = 0; i < row; ++i) {
                    sums[i] += matrix[i][r];
                    currSum += sums[i];
                    set<int>::iterator it = accuSet.lower_bound(currSum - k);
                    if (it != accuSet.end()) currMax = std::max(currMax, currSum - *it);
                    accuSet.insert(currSum);
                }
                maxSum = max(maxSum, currMax);
            }
        }
        return maxSum;
    }
};