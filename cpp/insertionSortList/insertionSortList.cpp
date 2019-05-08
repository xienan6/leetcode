// Source : https://leetcode.com/problems/insertion-sort-list/
// Author : Nan
// Date   : 2019-05-08
// Runtime: 48 ms

/*
* Insertion Sort.
*
* Time complexity O(n^2), Space complexity O(1)
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;
        ListNode *fa = new ListNode(-1), *lasthead = head;
        fa->next = head;
        head = head->next;
        while (head) {
            ListNode *cur = fa->next, *last = fa;
            while (cur->val < head->val) {
                cur = cur->next;
                last = last->next;
            }
            if (head != cur) {
                ListNode *next = head->next;
                last->next = head;
                head->next = cur;
                lasthead->next = next;
                head = next;
            }
            else {
                head = head->next;
                lasthead = lasthead->next;
            }
        }
        return fa->next;
    }
};