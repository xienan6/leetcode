// Source : https://leetcode.com/problems/multiply-strings/
// Author : Nan
// Date   : 2019-01-14
// 311 / 311 test cases passed.
// Runtime: 8 ms

/*
* Simulate.    
* 
* Time complexity O(nm), Space complexity O(n+m)
*/

class Solution {
public: 
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0') return "0";
        int N1 = num1.size();
        int N2 = num2.size();
        int carry = 0;
        string s(N1 + N2, '0');
        for (int i = N2-1; i >= 0; i--) {
            carry = 0;
            char c2 =  num2[i];
            for (int j = N1 - 1; j >= 0; j--){
                char c1 = num1[j];
                int digit = (s[i + j + 1] - '0')  + (c1 - '0') * (c2 - '0') + carry;
                carry = digit / 10;
                s[i + j + 1] = (digit % 10) + '0';
            }   
            s[i] += carry;
        }
        int start = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                start = i;
                break;
            }
        }
        return s.substr(start);
    }
};