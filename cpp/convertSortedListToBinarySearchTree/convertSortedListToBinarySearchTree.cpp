// Source : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Author : Nan
// Date   : 2019-04-05
// Runtime: 32 ms

/*
* Construct BST. [LEFT, MID) is left tree and 
* (MID, RIGHT] is right tree.  
*
* Time complexity O(n), Space complexity O(n)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> array;
        ListNode *r = head;
        while (r != NULL) {
            array.push_back(r->val);
            r = r->next;
        }
        return getSubTree(array, 0, array.size() - 1);
    }
    TreeNode* getSubTree(vector<int> &array, int left, int right) {
        if (left > right) return NULL;
        int mid = (right + left) >> 1;
        TreeNode *t = new TreeNode(array[mid]);
        t->left = getSubTree(array, left, mid - 1);
        t->right = getSubTree(array, mid + 1, right);
        return t;
    }
};