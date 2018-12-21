// Source : https://leetcode.com/problems/group-anagrams/
// Author : Nan
// Date   : 2018-12-21
// 101 / 101 test cases passed.
// Runtime: 20 ms

/*
* You can design a hash to represent each anagram. Like prime factor.
* Then use a hashmap to store each anagram.
*
* Time complexity O(nm), m is average length of each string, Space complexity O(nm)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        unordered_map<long, int> m;
        int l = strs.size();
        vector<vector<string>> result;
        for (int i = 0; i < l; i++) {
            long sum = 1;
            int ll = strs[i].length();
            for (int j = 0; j < ll; j++) {
                sum *= prime[strs[i][j] - 'a'];
            }
            vector<string> r;
            if (m.find(sum) == m.end()) {
                r.push_back(strs[i]);
                result.push_back(r);
                m[sum] = result.size() - 1;
            }
            else {
                result[m[sum]].push_back(strs[i]);
            }
        }
        return result;
    }
};