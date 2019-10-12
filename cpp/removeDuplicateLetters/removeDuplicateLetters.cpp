// Source : https://leetcode.com/problems/remove-duplicate-letters/
// Author : Nan
// Date   : 2019-10-12
// Runtime: 4 ms

/*
* 1) Skip this round directly when the current character is already on the stack
* 2) When the stack is empty or the current character is larger than the top 
*    character of the stack, it is directly pushed onto the stack.
* 3) When the top character of the stack is larger than the current character, 
*    and the hash table knows that there is a character at the top of the stack, 
*    the condition 2 is continuously pushed out of the stack, and then the current 
*    character is pushed onto the stack.
*
* Time complexity O(n), Space complexity O(n)
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> hash;
        unordered_map<char, bool> saved;
        for (char c : s) ++hash[c];
        string result; 
        for (char curr : s) {
            --hash[curr];
            if (saved[curr]) continue;
            while(!result.empty() && hash[result.back()] > 0 && result.back() >= curr) {
                saved[result.back()] = false;
                result.pop_back();
            }
            result += curr;
            saved[curr] = true;
        }
        return result;
    }
};