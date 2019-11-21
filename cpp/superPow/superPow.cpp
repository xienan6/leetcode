// Source : https://leetcode.com/problems/super-pow/
// Author : Nan
// Date   : 2019-11-21
// Runtime: 8 ms

/*
* Binary multiple.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        long long res = 1;
        for (int i = 0; i < b.size(); ++i) {
            res = pow(res, 10) * pow(a, b[i]) % 1337;
        }
        return res;
    }
    int pow(int x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x % 1337;
        return pow(x % 1337, n / 2) * pow(x % 1337, n - n / 2) % 1337;
    }
};