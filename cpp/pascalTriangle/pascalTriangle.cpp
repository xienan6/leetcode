// Source : https://leetcode.com/problems/pascals-triangle/
// Author : Nan
// Date   : 2019-04-14
// Runtime: 4 ms

/*
* Simulate.      
*
* Time complexity O(n^2), Space complexity O(n^2)
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
        Node *start = root, *dummy = new Node(0, NULL, NULL, NULL), *cur = dummy;
        while (start) {
            if (start->left) {
                cur->next = start->left;
                cur = start->left;
            }
            if (start->right) {
                cur->next = start->right;
                cur = start->right;
            }
            start = start->next;
            if (!start) {
                cur = dummy;
                start = dummy->next;
                dummy->next = NULL;
            }
        }
        return root;
    }
};