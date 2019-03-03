// Source : https://leetcode.com/problems/text-justification/
// Author : Nan
// Date   : 2019-03-03
// 27 / 27 cases passed.
// Runtime: 4 ms

/*
* String processing.   
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        string str = "";
        int m = maxWidth, start = 0;
        for (int i = 0; i < words.size(); i++) {
            if (m < i - start + words[i].length()) {
                int remainSpace = m;
                if (i == start + 1) {
                    string s(remainSpace, ' ');
                    str = words[start] + s;
                }
                else {
                    int remainSpaceNum = i - start - 1;
                    int space = remainSpace / remainSpaceNum + 1;
                    int spaceNum = remainSpaceNum - (space * remainSpaceNum - remainSpace);
                    string s(space - 1, ' ');
                    for (int j = start; j < start + spaceNum; j++) str = str + words[j] + s + ' ';
                    for (int j = start + spaceNum; j < i - 1; j++) str = str + words[j] + s;
                    str += words[i - 1];
                }
                res.push_back(str);
                str = "";
                m = maxWidth - words[i].length();
                start = i;
                if (i == words.size() - 1) {
                    string s(maxWidth - words[i].length(), ' ');
                    str = words[i] + s;
                    res.push_back(str);
                }
            }
            else if (i == words.size() - 1) {
                int lastRemainSpace = m - words[i].length() - i + start;
                for (int j = start; j < i; j++) str = str + words[j] + ' ';
                str += words[i];
                string s(lastRemainSpace, ' ');
                str += s;
                res.push_back(str);
            }
            else {
                m -= words[i].length();
            }
        }
        return res;
    }
};