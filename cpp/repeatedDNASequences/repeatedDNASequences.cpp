// Source : https://leetcode.com/problems/repeated-dna-sequences/
// Author : Nan
// Date   : 2019-06-02
// Runtime: 60 ms

/*
* Hashmap.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> r;
        if (s.length() < 10) return {};
        unordered_set<string> st;
        for (int i = 0; i < s.length() - 9; ++i) {
            string str = s.substr(i, 10);
            if (st.find(str) != st.end()) r.insert(str);
            else st.insert(str);
        }
        vector<string> res(r.begin(),r.end());
        return res;
    }
};