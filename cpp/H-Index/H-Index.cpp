// Source : https://leetcode.com/problems/h-index/
// Author : Nan
// Date   : 2019-09-09
// Runtime: 4 ms

/*
* Sort.  
*
* Time complexity O(nlogn), Space complexity O(1)
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int res = citations.size();
        for (int i = citations.size() - 1; i >= 0; --i) {
            if (citations.size() - i > citations[i]) {
                res = citations.size() - i - 1;
                break;
            }
        }
        return res;
    }
};