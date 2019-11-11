// Source : https://leetcode.com/problems/valid-perfect-square/
// Author : Nan
// Date   : 2019-11-11
// Runtime: 252 ms

/*
* Brute force is n^2k. Reverse all string and split it to check if there is a string exsit in dict.
*
* Time complexity O(nk^2), Space complexity O(n)
*/

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> dict;
        for (int i = 0; i < words.size(); ++i) {
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
        if(dict.find("")!=dict.end()){
            for(int i = 0; i < words.size(); i++){
                if(i == dict[""]) continue;
                if(isPalindrome(words[i])) ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self) 
            }
        }
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);
                 if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
                     ans.push_back({i, dict[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                 }
                 if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
                     ans.push_back({dict[right], i});
                 }
            }
        }   
        return ans;
    }
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length() / 2; ++i) {
            if (s[i] != s[s.length() - 1 - i]) return false;
        }
        return true;
    }
};