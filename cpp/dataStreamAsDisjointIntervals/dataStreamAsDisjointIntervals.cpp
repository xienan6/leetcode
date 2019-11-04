// Source : https://leetcode.com/problems/data-stream-as-disjoint-intervals
// Author : Nan
// Date   : 2019-11-04
// Runtime: 108 ms

/*
* Binary search.
*
* Time complexity O(nlogn), Space complexity O(n)
*/

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (intervals.empty()) intervals.push_back({val, val});
        else {
            int left = 0, right = intervals.size() - 1;
            if (intervals[left][0] > val + 1) {
                intervals.insert(intervals.begin(), {val, val});
                return;
            }
            else if (intervals[left][0] == val + 1) {
                intervals[left][0] = val;
                return;
            }
            else if (intervals[right][1] < val - 1) {
                intervals.push_back({val, val});
                return;
            }
            else if (intervals[right][1] == val - 1) {
                intervals[right][1] = val;
                return;
            }
            if (intervals.size() > 1) {
                while (left <= right) {
                    if (left + 1 == right) {
                        if (val == intervals[left][1] + 1 && val == intervals[right][0] - 1) {
                            intervals[left][1] = intervals[right][1];
                            intervals.erase(intervals.begin() + right);
                            return;
                        }
                        else if (val == intervals[left][1] + 1) {
                            intervals[left][1] = val;
                            return;
                        }
                        else if (val == intervals[right][0] - 1) {
                            intervals[right][0] = val;
                            return;
                        }
                        else if ((intervals[left][0] <= val && intervals[left][1] >= val) || (intervals[right][0] <= val && intervals[right][1] >= val)) return;
                        else {
                            intervals.insert(intervals.begin() + right, {val, val});
                            return;
                        }
                    }
                    if ((intervals[left][0] <= val && intervals[left][1] >= val) || (intervals[right][0] <= val && intervals[right][1] >= val)) return;
                    else {
                        int mid = (right - left) / 2 + left;
                        if (intervals[mid][0] <= val && intervals[mid][1] >= val) return;
                        if (val < intervals[mid][0]) right = mid;
                        else if (val > intervals[mid][1]) left = mid;
                    }
                }
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
private:
    vector<vector<int>> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */