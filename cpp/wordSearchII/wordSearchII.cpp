// Source : https://leetcode.com/problems/word-search-ii/
// Author : Nan
// Date   : 2019-06-24
// Runtime: 104 ms

/*
* Trie + DFS.
*
* Time complexity O(mn), Space complexity O(mn)
*/

class Solution {
private:
    struct TrieNode{
        unordered_map<char, TrieNode*> v;
        bool isWord = false;
    };
    TrieNode *root = NULL;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        unordered_set<string> se;
        string s = "";
        for (int i = 0; i < words.size(); ++i) addWord(words[i]);
        for (int j = 0; j < board.size(); ++j) {
            for (int k = 0; k < board[0].size(); ++k) {
                if (root->v.find(board[j][k]) != root->v.end()) dfs(board, j, k, root->v[board[j][k]], se, s + board[j][k]);
            }
        }
        vector<string> res(se.begin(), se.end());
        return res;
    }
    
    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* t, unordered_set<string> &se, string word) {
        if (t->isWord == true) se.insert(word);
        if (t->v.size() == 0) return;
        char c = board[x][y];
        board[x][y] = '-';
        if (x + 1 < board.size() && t->v.find(board[x + 1][y]) != t->v.end()) dfs(board, x + 1, y, t->v[board[x + 1][y]], se, word + board[x + 1][y]);
        if (y + 1 < board[0].size() && t->v.find(board[x][y + 1]) != t->v.end()) dfs(board, x, y + 1, t->v[board[x][y + 1]], se, word + board[x][y + 1]);
        if (x - 1 >= 0 && t->v.find(board[x - 1][y]) != t->v.end()) dfs(board, x - 1, y, t->v[board[x - 1][y]], se, word + board[x - 1][y]);
        if (y - 1 >= 0 && t->v.find(board[x][y - 1]) != t->v.end()) dfs(board, x, y - 1, t->v[board[x][y - 1]], se, word + board[x][y - 1]);
        board[x][y] = c;
    }
    void addWord(string word) {
        TrieNode *t = root;
        for (int i = 0; i < word.length(); ++i) {
            if (t->v.find(word[i]) == t->v.end()) t->v[word[i]] = new TrieNode();
            t = t->v[word[i]];
        }
        t->isWord = true;
    }
};