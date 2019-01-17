// Source : https://leetcode.com/problems/palindrome-partitioning
// Author : Nan
// Date   : 2019-01-17
// 22 / 22 test cases passed.
// Runtime: 24 ms

/*
* Recursive.  
*
* Time complexity O(n!), Space complexity O(n!)
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> out;
        dfs(s, 0, out, result);
        return result;
    }
    
    void dfs(string s, int start, vector<string> out, vector<vector<string>> &result) {
        int l = s.length();
        if (start == l) {
            result.push_back(out);
            return;
        }
        for (int i = start; i < l; i++) {
            if (isPalindrome(s, start, i)) {
                out.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, out, result);
                out.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};