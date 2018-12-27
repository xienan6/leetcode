// Source : https://leetcode.com/problems/insert-interval/
// Author : Nan
// Date   : 2018-12-27
// 154 / 154 test cases passed.
// Runtime: 16 ms

/*
* Traverse.
* 
* Time complexity O(n), Space complexity O(n)
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval n) {
        vector<Interval> sol;
        int i = 0;
        while (i < intervals.size() && intervals[i].end < n.start) {
            sol.push_back(intervals[i++]);
        }
        while (i < intervals.size() && n.end >= intervals[i].start) {
            n.start = min(n.start, intervals[i].start);
            n.end = max(n.end, intervals[i++].end);
        }
        sol.push_back(n);
        while (i < intervals.size()) {
            sol.push_back(intervals[i++]);
        }
        return sol;
    }
};