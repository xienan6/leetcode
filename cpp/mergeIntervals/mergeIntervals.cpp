// Source : https://leetcode.com/problems/merge-intervals
// Author : Nan
// Date   : 2018-12-23
// 169 / 169 test cases passed.
// Runtime: 8 ms

/*
* Sort the array and greedy.  
* 
* Time complexity O(nlogn), Space complexity O(n)
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
    static int cmp (Interval i1, Interval i2) {
        return i1.start < i2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> result;
        if (intervals.empty()) {
            return result;
        }
        result.push_back(Interval(intervals[0].start, intervals[0].end));
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start > result[result.size() - 1].end) {
                result.push_back(Interval(intervals[i].start, intervals[i].end));
            }
            else if (intervals[i].end > result[result.size() - 1].end){
                result[result.size() - 1].end = intervals[i].end;
            }
        }
        return result;
    }
};