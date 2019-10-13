// Source : https://leetcode.com/problems/maximum-equal-frequency
// Author : Nan
// Date   : 2019-10-13
// Runtime: 64 ms

/*
* first situation: There are only two frequencies( A and B) of numbers appearing in prefixes,where A=B+1 and only one digit's frequency is A.
* in this situation, we can remove one of the digits whose frequency is A.
*
* second situation: There are only two frequencies( A and B) of numbers appearing in prefixes,where A=1 and B≠1 and only one digit's frequency is A.
* in this situation, we can remove the digit whose frequency is 1.
*
* third situation: All digits in nums appear only one.
* in this situation, we can remove any of digit to get the ans.
*
* fourth situation: All digits in nums are the same.
* in this situation, we can remove any of digit to get the ans.
*
* Time complexity O(n), Space complexity O(1)
*/

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        vector<int> fre(100001, 0);
        vector<int> cnt(100001, 0);
        int maxcnt = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ++cnt[nums[i]];
            ++fre[cnt[nums[i]]];
            maxcnt = max(maxcnt, cnt[nums[i]]);
            if ((fre[maxcnt] == 1 && maxcnt + (fre[maxcnt - 1] - 1) * (maxcnt - 1) == i + 1 ) 
                || (fre[maxcnt] * maxcnt + 1 == i + 1))
                res = i + 1;
        }
        if (maxcnt == 1) return nums.size();
        return res;
    }
};