// Source : https://leetcode.com/problems/integer-to-english-words
// Author : Nan
// Date   : 2019-09-08
// Runtime: 8 ms

/*
* Recursion solution. 
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<string> d = {"", " Thousand", " Million", " Billion"};
        vector<string> v1 = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
        vector<string> v2 = {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
        string res = "", s;
        int i = 0, n;
        while (num / 1000) {
            s = "";
            n = num % 1000;
            if (n == 0) {
                num /= 1000;
                i++;
                continue;
            }
            s = v1[n / 100] + (n / 100 ? " Hundred" : "");
            n %= 100;
            if (n / 10 == 1) s = s + v1[n];
            else s = s + v2[n / 10] + v1[n % 10];
            s = s + d[i++];
            num /= 1000;
            res = s + res;
        }
        s = "";
        if (num == 0) return res.substr(1);
        if (num >= 100) {
            n = num % 1000;
            s = v1[n / 100] + (n / 100 ? " Hundred" : "");
        }
        if (num >= 10) {
            n = num % 100;
            if (n / 10 == 1) s = s + v1[n];
            else s = s + v2[n / 10] + v1[n % 10];
        }
        else {
            s = s + v1[num];
        }
        s = s + d[i];
        res = s + res;
        return res.substr(1);
    }
};