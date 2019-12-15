// Source : https://leetcode.com/problems/perfect-rectangle
// Author : Nan
// Date   : 2019-12-14
// Runtime: 208 ms

/*
* Each point is a single point or a point with two rectangles or 
* a point with four rectangles. The result will only leave four points with a rectangle.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> st;
        int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN, area = 0;
        for (auto rect : rectangles) {
            min_x = min(min_x, rect[0]);
            min_y = min(min_y, rect[1]);
            max_x = max(max_x, rect[2]);
            max_y = max(max_y, rect[3]);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            string s1 = to_string(rect[0]) + "_" + to_string(rect[1]);
            string s2 = to_string(rect[0]) + "_" + to_string(rect[3]);
            string s3 = to_string(rect[2]) + "_" + to_string(rect[3]);
            string s4 = to_string(rect[2]) + "_" + to_string(rect[1]);
            if (st.count(s1)) st.erase(s1);
            else st.insert(s1);
            if (st.count(s2)) st.erase(s2);
            else st.insert(s2);
            if (st.count(s3)) st.erase(s3);
            else st.insert(s3);
            if (st.count(s4)) st.erase(s4);
            else st.insert(s4);
        }
        string t1 = to_string(min_x) + "_" + to_string(min_y);
        string t2 = to_string(min_x) + "_" + to_string(max_y);
        string t3 = to_string(max_x) + "_" + to_string(max_y);
        string t4 = to_string(max_x) + "_" + to_string(min_y);
        if (!st.count(t1) || !st.count(t2) || !st.count(t3) || !st.count(t4) || st.size() != 4) return false;
        return area == (max_x - min_x) * (max_y - min_y);
    }
};