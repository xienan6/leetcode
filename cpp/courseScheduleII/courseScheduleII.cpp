// Source : https://leetcode.com/problems/course-schedule-ii/
// Author : Nan
// Date   : 2019-06-22
// Runtime: 32 ms

/*
* Use a queue to store course whose indegree is 0. 
*
* Time complexity O(n^2), Space complexity O(n^2)
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        
        for (auto &a : prerequisites) {
            graph[a[1]].push_back(a[0]);
            in[a[0]]++;
        }
        
        queue<int> q;
        
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0)
                q.push(i);
        }
        
        while (!q.empty()) {
            int t = q.front();
            ret.push_back(t);
            q.pop();
            
            for (auto &a : graph[t]) {
                in[a]--;
                
                if (in[a] == 0)
                    q.push(a);
            }
        }
        
        if (ret.size() != numCourses)
            ret.clear();
        
        return ret;
    }
};