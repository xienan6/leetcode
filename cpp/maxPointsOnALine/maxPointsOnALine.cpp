// Source : https://leetcode.com/problems/max-points-on-a-line/
// Author : Nan
// Date   : 2019-05-10
// Runtime: 4 ms

/*
* Use a map to calculate gradient of every two points. 
* Notice there are same points.    
*
* Time complexity O(n^2logn), Space complexity O(n)
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> m;
            int dulp = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++dulp;
                    continue;
                }
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int d = gcd(dx, dy);
                ++m[{dx / d, dy / d}];
            }
            res = max(res, dulp);
            for (auto j = m.begin(); j != m.end(); ++j) {
                res = max(res, j->second + dulp);
            }
        }
        return res;
    }
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};