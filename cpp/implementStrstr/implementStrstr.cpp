// Source : https://leetcode.com/problems/implement-strstr
// Author : Nan
// Date   : 2018-12-18
// 74 / 74 test cases passed.
// Runtime: 4 ms

/*
* kmp
*
* Time complexity O(n+m), Space complexity O(m)
*/

class Solution {
public:
     void get_next(vector<int> &next,string needle) {
        int i = 0, j = -1;
        next[i] = j;      
        while (i < needle.length() - 1) {
            while (j != -1 && needle[i] != needle[j]) 
                j = next[j];     
            ++i; ++j;
            //特殊情况，这里即为优化之处。考虑下AAAAB, 防止4个A形成0123在匹配时多次迭代。
            if (needle[i] == needle[j]) next[i] = next[j]; 
            else next[i] = j;
         }
        
    }
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        int i = 0, j = 1;
        vector<int> next(needle.length() + 5);
        get_next(next, needle);
        while (i <= haystack.length() && j <= needle.length()) {
            if (j == 0 || haystack[i] == needle[j - 1]) {
                i++,j++;
            }
            else {
                j = next[j - 1] + 1;
            }
        }
        if (j > needle.length()) {
            return i - needle.length();
        }
        else {
            return -1;
        }
    }
};