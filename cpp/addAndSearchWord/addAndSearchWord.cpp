// Source : https://leetcode.com/problems/add-and-search-word-data-structure-design
// Author : Nan
// Date   : 2019-06-23
// Runtime: 124 ms

/*
* Trie.
*
* Time complexity O(n), Space complexity O(n)
*/

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *t = root;
        for (int i = 0; i < word.length(); ++i) {
            if (t->v.find(word[i]) == t->v.end()) t->v[word[i]] = new TrieNode();
            t = t->v[word[i]];
        }
        t->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        queue<TrieNode*> q;
        q.push(root);
        for (int i = 0; i < word.length(); ++i) {
            int n = q.size();
            bool findone = false;
            if (word[i] == '.') {
                for (int j = 0; j < n; ++j) {
                    TrieNode *t = q.front();
                    q.pop();
                    for (unordered_map<char, TrieNode*>::iterator k = t->v.begin(); k != t->v.end(); k++) {
                        q.push(k->second);
                        findone = true;
                    }
                }
            }
            else {
                for (int j = 0; j < n; ++j) {
                    TrieNode *t = q.front();
                    q.pop();
                    if (t->v.find(word[i]) != t->v.end()) {
                        findone = true;
                        q.push(t->v[word[i]]);
                    }
                }
            }
            if (findone == false) return false;
        }
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            TrieNode *t = q.front();
            q.pop();
            if (t->isWord == true) return true;
        }
        return false;
    }
private:
    struct TrieNode{
        unordered_map<char, TrieNode*> v;
        bool isWord = false;
    };
    TrieNode *root = NULL;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */