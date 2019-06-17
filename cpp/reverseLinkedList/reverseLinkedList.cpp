// Source : https://leetcode.com/problems/reverse-linked-list/
// Author : Nan
// Date   : 2019-06-17
// Runtime: 12 ms

/*
* Stack.
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p = head;
        stack<ListNode*> s;
        while (p) {
            s.push(p);
            p = p->next;
        }
        p = s.top();
        s.pop();
        ListNode *res = p;
        while (!s.empty()) {
            p->next = s.top();
            s.pop();
            p = p->next;
        }
        p->next = NULL;
        return res;
    }
};