// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// Author : Nan
// Date   : 2018-12-17
// 25 / 25 test cases passed.
// Runtime: 0 ms

/*
* Recursive. Or you can use a vector and each character 
* in the end of each string in old vector.
*
* Time complexity O(n!), Space complexity O(n!)
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int l = digits.length();
        vector<string> result;
        if (l == 0) return result;
        string represent[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int j = 0; j < represent[digits[0] - '2'].length(); j++) {
            string str = "";
            result.push_back(str + represent[digits[0] - '2'][j]);
        }
        for (int i = 1; i < l; i++) {
            int n = result.size();
            for (int k = 0; k < n; k++) {
                for (int j = 0; j < represent[digits[i] - '2'].length(); j++) {
                    result.push_back(result[0] + represent[digits[i] - '2'][j]);
                }
                result.erase(result.begin());
            }
        }
        return result;
    }
};