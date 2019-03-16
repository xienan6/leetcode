// Source : https://leetcode.com/problems/partition-list/
// Author : Nan
// Date   : 2019-03-16
// Runtime: 8 ms

/*
* Use two linklist.    
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1 = new ListNode(-1), *l2 = new ListNode(-1); 
        ListNode *h = head, *res = l1, *l3 = l2;
        while (h) {
            if (h->val < x) l1->next = h, l1 = l1->next;
            else l2->next = h, l2 = l2->next;
            h = h->next;
        }
        l2->next = NULL;
        l1->next = l3->next;
        return res->next;
    }
};