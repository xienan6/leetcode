// Source : https://leetcode.com/problems/count-and-say/
// Author : Nan
// Date   : 2019-01-01
// 18 / 18 test cases passed.
// Runtime: 4 ms

/*
* Simulate.  
* 
* Time complexity O(n^2), Space complexity O(n)
*/

class Solution {
public:
    string countAndSay(int n) {
        switch(n) {
            case 1: return "1";
            case 2: return "11";
            case 3: return "21";
            case 4: return "1211";
            case 5: return "111221";
        }
        string str, result = "111221";
        int cnt;
        for (int i = 5; i < n; i++) {
            cnt = 1;
            str = "";
            for (int j = 1; j < result.length(); j++) {
                if (result[j] == result[j - 1]) cnt++;
                else {
                    str = str + (char)(cnt + '0') + result[j - 1];
                    cnt = 1;
                }
            }
            result = str + (char)(cnt + '0') + result[result.length() - 1];
        }
        return result;
    }
};