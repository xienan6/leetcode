// Source : https://leetcode.com/problems/queue-reconstruction-by-height/
// Author : Nan
// Date   : 2019-12-30
// Runtime: 180 ms

/*
* Smaller and the second is zero are more forward.
*
* Time complexity O(n^2), Space complexity O(n)
*/

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        vector<vector<int>> p(people);
        while (!people.empty()) {
            int min = INT_MAX, index = -1;
            for (int i = 0; i < people.size(); ++i) {
                if (people[i][1] == 0 && people[i][0] < min) {
                    min = people[i][0];
                    index = i;
                }
            }
            for (int i = 0; i < people.size(); ++i) {
                if (i != index && people[i][0] <= min) {
                    --people[i][1];
                }
            }
            res.push_back(p[index]);
            people.erase(people.begin() + index);
            p.erase(p.begin() + index);
        }
        return res;
    }
};