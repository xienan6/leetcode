// Source : https://leetcode.com/problems/word-ladder/
// Author : Nan
// Date   : 2019-01-15
// 39 / 39 test cases passed.
// Runtime: 68 ms

/*
* BFS.  
*
* Time complexity -, Space complexity -
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> newWordList;
        int l = wordList.size();
        int ll = beginWord.length();
        string newWord;
        for (int i = 0; i < l; i++) {
            newWordList.insert(wordList[i]);
        }
        if (newWordList.find(endWord) == newWordList.end()) {
            return 0;
        }
        newWordList.erase(beginWord);
        queue<string> bfsQueue;
        bfsQueue.push(beginWord);
        int result = 1;
        while (!bfsQueue.empty()) {
            int lll = bfsQueue.size();
            for (int si = 0; si < lll; si++) {
                newWord = bfsQueue.front();
                bfsQueue.pop();
                if (newWord == endWord) {
                    return result;
                }
                for (int i = 0; i < ll; i++) {
                    char letter = newWord[i];
                    for (int j = 0; j < 26; j++) {
                        newWord[i] = 'a' + j;
                        if (newWordList.find(newWord) != newWordList.end()) {
                            bfsQueue.push(newWord);
                            newWordList.erase(newWord);
                        }
                    }
                    newWord[i] = letter;
                }
            }
            result++;
        }
        return 0;
    }
};