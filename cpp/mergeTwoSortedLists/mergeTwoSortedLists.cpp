// Source : https://leetcode.com/problems/merge-two-sorted-lists
// Author : Nan
// Date   : 2018-12-12
// 208 / 208 test cases passed.
// Runtime: 8 ms

/*
* simulate
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode  *result, *p, *newnode, *ll1 = l1, *ll2 = l2;
        if (ll1 == NULL)
            return ll2;
        if(ll2 == NULL)
            return ll1;
        if (ll1 == NULL && ll2 == NULL)
            return result;
        if (ll1->val >= ll2->val) {
            result = new ListNode(ll2->val);
            ll2 = ll2->next;
        }
        else {
            result = new ListNode(ll1->val);
            ll1 = ll1->next;
        }
        p = result;
        while (ll1 != NULL && ll2 != NULL) {
            if (ll1->val >= ll2->val) {
                newnode = new ListNode(ll2->val);
                p->next = newnode;
                p = newnode;
                ll2 = ll2->next;
            }
            else {
                newnode = new ListNode(ll1->val);
                p->next = newnode;
                p = newnode;
                ll1 = ll1->next;
            }
        }
        if (ll1 == NULL) {
            p->next = ll2;
        }
        else {
            p->next = ll1;
        }
        return result;
    }
};