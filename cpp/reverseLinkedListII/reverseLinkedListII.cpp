// Source : https://leetcode.com/problems/reverse-linked-list-ii/
// Author : Nan
// Date   : 2019-03-20
// Runtime: 8 ms

/*
* Insert node[m+1,n] between node[m-1] and node[m].         
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        for (int i = 1; i < m; i++) pre = pre->next;
        ListNode *cur = pre->next;
        for (int i = m; i < n; i++) {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }
        return dummy->next;
    }
};