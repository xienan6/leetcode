// Source : https://leetcode.com/problems/the-skyline-problem/
// Author : Nan
// Date   : 2019-07-01
// Runtime: 40 ms

/*
* Sort and compare one by one.
*
* Time complexity O(nlogn), Space complexity O(n)
*/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());
        m.insert(0);
        for (auto &a : h) {
            if (a[1] < 0) m.insert(-a[1]);
            else m.erase(m.find(a[1]));
            cur = *m.rbegin();
            //cout << a[0] << " " << a[1] << endl;
            if (cur != pre) {
                //cout << " " << a[0] << " " << cur << endl;
                res.push_back({a[0], cur});
                pre = cur;
            }
        }
        return res;
    }
};