// Source : https://leetcode.com/problems/permutation-sequence/
// Author : Nan
// Date   : 2019-02-24
// 200 / 200 cases passed.
// Runtime: 4 ms

/*
* If the first number is constant, there are 
* (n-1)! combinations. If the first number and 
* the second number are constant, there are (n-2)! 
* combinations. And so on use the remainder and 
* you can get the anwser.    
* 
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string res, num = "123456789";
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++) f[i] = f[i - 1] * i;
        k--;
        for (int i = n; i >= 1; i--) {
            int j = k / f[i - 1];
            k %= f[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;    
    }
};