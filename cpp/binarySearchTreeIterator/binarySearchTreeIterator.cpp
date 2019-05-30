// Source : https://leetcode.com/problems/binary-search-tree-iterator/
// Author : Nan
// Date   : 2019-05-30
// Runtime: 60 ms

/*
* Inorder.
*
* Time complexity O(1), Space complexity O(1)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if (root) dfs(root);
    }
    
    void dfs(TreeNode* r) {
        if (r->left) dfs(r->left);
        q.push(r);
        if (r->right) dfs(r->right);
    }
    
    /** @return the next smallest number */
    int next() {
        int t = q.front()->val;
        q.pop();
        return t;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (q.empty()) return false;
        else return true;
    }
private:
    queue<TreeNode*> q;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */