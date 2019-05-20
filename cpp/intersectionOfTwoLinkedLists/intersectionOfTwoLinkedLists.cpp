// Source : https://leetcode.com/problems/intersection-of-two-linked-lists/
// Author : Nan
// Date   : 2019-05-20
// Runtime: 48 ms

/*
* Calculate length of two list and left them with same 
* length. Then traverse them at the same time.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0, l2 = 0;
        ListNode *p1 = headA, *p2 = headB;
        while (p1) {
            ++l1;
            p1 = p1->next;
        }
        while (p2) {
            ++l2;
            p2 = p2->next;
        }
        p1 = headA;
        p2 = headB;
        if (l1 > l2) {
            for (int i = 0; i < l1 - l2; ++i)
                p1 = p1->next;
        }
        else if (l1 < l2) {
            for (int i = 0; i < l2 - l1; ++i)
                p2 = p2->next;
        }
        while (p1) {
            if (p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};