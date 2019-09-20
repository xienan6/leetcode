// Source : https://leetcode.com/problems/serialize-and-deserialize-binary-tree
// Author : Nan
// Date   : 2019-09-20
// Runtime: 92 ms

/*
* BFS + QUEUE + simulate.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string res = "[";
        if (root) {
            res += to_string(root->val);
            q.push(root->left);
            q.push(root->right);
        }
        else {
            return "[]";
        }
        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            if (t) {
                res = res + "," + to_string(t->val);
                q.push(t->left);
                q.push(t->right);
            }
            else {
                res += ",null";
            }
        }
        int i = res.length() - 1;
        while (res[i] < '0' || res[i] > '9') --i;
        res = res.substr(0, i + 1) + "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data[1] == 'n' || data[1] == ']') return NULL;
        int start = 1, i = 1;
        while (data[i++] != ',' && data[i] != ']');
        TreeNode *root = new TreeNode(atoi(data.substr(start, i - start).c_str()));
        start = i;
        TreeNode *p = root;
        queue<TreeNode*> q;
        q.push(p);
        while (data[start] != ']') {
            TreeNode *t = q.front();
            q.pop();
            while (data[i] != ']' && data[i++] != ',');
            if (data[start] == 'n') t->left = NULL;
            else {
                t->left = new TreeNode(atoi(data.substr(start, i - start).c_str()));
                q.push(t->left);
            }
            start = i;
            while (data[i] != ']' && data[i++] != ',');
            if (data[start] == 'n' || data[start] == ']') t->right = NULL;
            else {
                t->right = new TreeNode(atoi(data.substr(start, i - start).c_str()));
                q.push(t->right);
            }
            start = i;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));