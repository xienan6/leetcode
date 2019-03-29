// Source : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Author : Nan
// Date   : 2019-03-29
// Runtime: 8 ms

/*
* BFS.  
*
* Time complexity O(n), Space complexity O(n)
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> st;
        if (!root) return res;
        st.push_back(root);
        int cnt = 1;
        while (!st.empty()) {
            vector<int> r;
            int n = st.size();
            if (cnt % 2 == 1) {
                for (int i = 0; i < n; ++i) r.push_back(st[i]->val);
            }
            else {
                for (int i = n - 1; i >= 0; --i) r.push_back(st[i]->val);
            }
            res.push_back(r);
            cnt++;
            for (int i = 0; i < n; ++i) {
                if (st[0]->left != NULL) st.push_back(st[0]->left);
                if (st[0]->right != NULL) st.push_back(st[0]->right);
                st.erase(st.begin());
            }
        }
        return res;
    }
};