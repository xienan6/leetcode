// Source : https://leetcode.com/problems/remove-linked-list-elements/
// Author : Nan
// Date   : 2019-06-12
// Runtime: 24 ms

/*
* Linked list operation.  
*
* Time complexity O(n), Space complexity O(1)
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *f = new ListNode(-1), *last = f, *cur = head;
        f->next = head;
        while (cur) {
            if (cur->val == val) last->next = cur->next; 
            else last = last->next;
            cur = cur->next;
        }
        return f->next;
    }
};