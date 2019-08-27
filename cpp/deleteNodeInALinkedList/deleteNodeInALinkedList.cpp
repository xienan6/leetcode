// Source : https://leetcode.com/problems/delete-node-in-a-linked-list/
// Author : Nan
// Date   : 2019-08-27
// Runtime: 12 ms

/*
* -
*
* Time complexity O(1), Space complexity O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};