// Source : https://leetcode.com/problems/course-schedule/
// Author : Nan
// Date   : 2019-06-18
// Runtime: 12 ms

/*
* BFS. Find the point where the indegree is 0. Push the
* point where the indegree is 0 into queue. Check whether 
* there is a point where the indegree is not 0.
*
* Time complexity O(n^2), Space complexity O(n^2)
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> v(numCourses, vector<int>(0));
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); ++i) {
            ++indegree[prerequisites[i][0]];
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int i = 0; i < v[t].size(); ++i) {
                --indegree[v[t][i]];
                if(indegree[v[t][i]] == 0){
                    q.push(v[t][i]);
                }
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] != 0)
                return false;
        }
        return true;
    }
};