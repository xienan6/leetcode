// Source : https://leetcode.com/problems/minimum-genetic-mutation/
// Author : Nan
// Date   : 2020-01-14
// Runtime: 4 ms

/*
* BFS. 
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (bank.empty()) return -1;
        vector<char> gens{'A','C','G','T'};
        unordered_set<string> s{bank.begin(), bank.end()};
        unordered_set<string> visited;
        queue<string> q{{start}};
        int level = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                string t = q.front(); q.pop();
                if (t == end) return level;
                for (int j = 0; j < t.size(); ++j) {
                    char old = t[j];
                    for (char c : gens) {
                        t[j] = c;
                        if (s.count(t) && !visited.count(t)) {
                            visited.insert(t);
                            q.push(t);
                        }
                    }
                    t[j] = old;
                }
            }
            ++level;
        }
        return -1;
        
        
    }
    
};