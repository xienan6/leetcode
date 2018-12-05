// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Author : Nan
// Date   : 2018-12-04

/*
* We can use a hashmap to check if a character is already in the substring.
* If a character is already in the substring, we can continue to search from
* its index + 1. Because all index can search twice. Time complexity is O(n).
* We know characters are char type, and we can use a int[128] to replace a hashmap.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int* lastPostion = new int[128];
        memset(lastPostion, -1, 512);
        int sum = 0, result = 0, i = 0;
        while(i < n - result + sum) {
            if(lastPostion[(int)s[i]] == -1) {
                lastPostion[(int)s[i]] = i;
                sum++;
                i++;
                if(sum > result) {
                    result = sum;
                }
            }
            else {
                sum = 0;
                i = lastPostion[(int)s[i]] + 1;
                memset(lastPostion, -1, 512);
            }
        }
        return result;
    }
};
