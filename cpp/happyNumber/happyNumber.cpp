// Source : https://leetcode.com/problems/happy-number/
// Author : Nan
// Date   : 2019-06-11
// Runtime: 4 ms

/*
* Hashmap.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1) {
            if (s.find(n) != s.end()) return false;
            s.insert(n);
            string str = to_string(n);
            n = 0;
            for (int i = 0; i < str.length(); ++i) n += ((str[i] - '0') * (str[i] - '0'));
        }
        return true;
    }
};