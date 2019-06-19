// Source : https://leetcode.com/problems/implement-trie-prefix-tree/
// Author : Nan
// Date   : 2019-06-19
// Runtime: 100 ms

/*
* Trie.
*
* Time complexity O(-), Space complexity O(-)
*/

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); ++i) {
            if (p->m.find(word[i]) == p->m.end()) p->m[word[i]] = new TrieNode();
            p = p->m[word[i]];
        }
        p->isWord[word[word.length() - 1]] = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); ++i) {
            if (p->m.find(word[i]) == p->m.end()) return false;
            p = p->m[word[i]];
        }
        return p->isWord[word[word.length() - 1]];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (int i = 0; i < prefix.length(); ++i) {
            if (p->m.find(prefix[i]) == p->m.end()) return false;
            p = p->m[prefix[i]];
        }
        return true;
    }
private:
    struct TrieNode{
        unordered_map<char, TrieNode*> m;
        unordered_map<char, bool> isWord;
    };
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */