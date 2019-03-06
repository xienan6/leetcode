// Source : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Author : Nan
// Date   : 2019-03-06
// 173 / 173 cases passed.
// Runtime: 32 ms

/*
* Use two hashmap. Travel all the words combinations 
* to maintain a window. There are wordLength times travel. 
* One left side of the window, the other right side of 
* the window. So, time complexity O(wordLength * 2 * N/wordLength) = O(2N)    
*
* Time complexity O(n), Space complexity O(m)
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int l = s.length(), cnt = words.size();
        vector<int> res;
        if (l <= 0 || cnt <= 0) return res;
        int wordLength = words[0].length();
        unordered_map<string, int> wordsInS;
        for (int i = 0; i < cnt; i++) wordsInS[words[i]]++;
        for (int i = 0; i < wordLength; i++) {
            unordered_map<string, int> sInWords;
            int start = i, count = 0;
            for (int j = i; j < s.length(); j += wordLength) {
                string str = s.substr(j, wordLength);
                // valid word
                if (wordsInS.count(str)) {
                    sInWords[str]++;
                    if (sInWords[str] <= wordsInS[str]) count++;
                    // repeat word, shift window
                    else {
                        // a more word, advance the window left side possiablly
                        while (sInWords[str] > wordsInS[str]) {
                            string str1 = s.substr(start, wordLength);
                            sInWords[str1]--;
                            if (sInWords[str1] < wordsInS[str1]) count--;
                            start += wordLength;
                        }
                    }
                    // come to a result
                    if (count == cnt) {
                        res.push_back(start);
                        // advance one word
                        sInWords[s.substr(start, wordLength)]--;
                        count--;
                        start += wordLength;
                    }
                }
                // not a valid word, reset all vars
                else {
                    sInWords.clear();
                    count = 0;
                    start = j + wordLength;
                }
            }
        }
        return res;
    }
};