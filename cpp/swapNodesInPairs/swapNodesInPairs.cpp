// Source : https://leetcode.com/problems/swap-nodes-in-pairs/description/
// Author : Nan
// Date   : 2018-12-16
// 55 / 55 test cases passed.
// Runtime: 0 ms

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p1, *p2, *tmp;
        if (head != NULL && head->next != NULL) {
            p1 = head;
            p2 = head->next;
            head = p2;
            p1->next = p2->next;
            p2->next = p1;
            tmp = p1; 
            while (p1->next != NULL && p1->next->next != NULL) {
                p2 = p2->next->next->next;
                p1 = p1->next;
                tmp->next = p2;
                p1->next = p2->next;
                p2->next = p1;
                tmp = p1;
            }
        }
        return head;
    }
};