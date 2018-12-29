// Source : https://leetcode.com/problems/add-binary
// Author : Nan
// Date   : 2018-12-29
// 294 / 294 test cases passed.
// Runtime: 0 ms

/*
* simulate.  
* 
* Time complexity O(n+m), Space complexity O(1)
*/

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        return s;
    }
};