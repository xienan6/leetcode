// Source : https://leetcode.com/problems/reconstruct-itinerary/
// Author : Nan
// Date   : 2019-10-23
// Runtime: 4 ms

/*
* DFS.
*
* Time complexity O(2^n), Space complexity O(2^n)
*/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for (int i = 0; i < tickets.size(); ++i) {
            m[tickets[i][0]].insert(tickets[i][1]);
        }
        dfs(m, "JFK", res);
        return vector<string> (res.rbegin(), res.rend());
    }
    void dfs(unordered_map<string, multiset<string>>& m, string s, vector<string> &res) {
        while (m[s].size()) {
            string t = *m[s].begin();
            m[s].erase(m[s].begin());
            dfs(m, t, res);
        }
        res.push_back(s);
    }
};