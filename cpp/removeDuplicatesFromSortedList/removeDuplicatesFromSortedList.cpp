// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Author : Nan
// Date   : 2019-03-13
// Runtime: 16 ms

/*
* Simulate.  
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pre = head, *cur = head->next;
        while (cur) {
            while (cur && cur->val == pre->val) cur = cur->next;
            pre->next = cur;
            pre = cur;
        }
        return head;
    }
};