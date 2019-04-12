// Source : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author : Nan
// Date   : 2019-04-12
// Runtime: 64 ms

/*
* BFS.    
*
* Time complexity O(n), Space complexity O(logn)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root != NULL && root->left != NULL) {
            q.push(root->left);
            q.push(root->right);
        }
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* n1 = q.front();
                q.pop();
                if (i != n - 1) {
                    n1->next = q.front();
                }
                else {
                    n1->next = NULL;
                }
                if (n1->left != NULL) {
                    q.push(n1->left);
                    q.push(n1->right);
                }
            }
        }
        return root;
    }
};