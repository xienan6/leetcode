// Source : https://leetcode.com/problems/additive-number/
// Author : Nan
// Date   : 2019-09-27
// Runtime: 0 ms

/*
* Recursion solution.  
*
* Time complexity O(2^n), Space complexity O(2^n)
*/

class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.length() < 3) return false;
        bool flag = true;
        for (int i = 0; i < num.length(); ++i) {
            if (num[i] != '0') {
                flag = false;
                break;
            }
        }
        if (flag) return true;
        flag = false;
        long long num1, num2;
        for (int i = 0; i < num.length() - 2 && !flag; ++i) {
            for (int j = i + 1; j < num.length() - 1&& !flag; ++j) {
                dfs(num, j + 1, num.substr(0, i + 1), num.substr(i + 1, j - i), flag);
            }
        }
        return flag;
    }
    void dfs(string &num, int start, string num1, string num2, bool &flag) {
        if (start == num.length() && num2[0] != '0') flag = true;
        if (flag || (num1[0] == '0' && num1.length() > 1) || (num2[0] == '0' && num2.length() > 1) || num.substr(start).length() < max(num1.length(), num2.length())) return;
        long long n1 = atol(num1.c_str()), n2 = atol(num2.c_str());
        if (n1 + n2 == atol(num.substr(start, max(num1.length(), num2.length())).c_str()))
            dfs(num, start + max(num1.length(), num2.length()), num2, num.substr(start, max(num1.length(), num2.length())), flag);
        if (n1 + n2 == atol(num.substr(start, max(num1.length(), num2.length()) + 1).c_str()))
            dfs(num, start + max(num1.length(), num2.length()) + 1, num2, num.substr(start, max(num1.length(), num2.length()) + 1), flag);
    }
};