// Source : https://leetcode.com/problems/text-justification/
// Author : Nan
// Date   : 2019-03-04
// 254 / 254 cases passed.
// Runtime: 12 ms

/*
* String processing.   
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    string simplifyPath(string path) {
        string str = "";
        int start, i = 0;
        vector<string> v;
        while (i < path.length()) {
            while (i < path.length() && path[i] == '/') i++;
            start = i;
            while (i < path.length() && path[i] != '/') i++;
            if ((i - start == 1 && path[start] == '.') || i - start < 1) continue;
            else if (i - start == 2 && path[start] == '.' && path[start + 1] == '.') {
                if (v.size() > 0) v.pop_back();
            }
            else {
                v.push_back(path.substr(start, i - start));
            }
        }
        for (int j = 0; j < v.size(); j++) str = str + '/' + v[j];
        if (str.length() == 0) str = '/';
        return str;
    }
};