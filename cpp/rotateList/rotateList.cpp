// Source : https://leetcode.com/problems/rotate-list
// Author : Nan
// Date   : 2019-02-25
// 231 / 231 cases passed.
// Runtime: 12 ms

/*
* Firstly, calculate the length of the list. 
* Then mod k and use two pointers which their 
* intervals are k mod length.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int length = 0;
        ListNode *s, *h = head;
        while (h != NULL) {
            length++;
            h = h->next;
        }
        k %= length;
        s = head;
        h = head;
        for (int i = 0; i < k; i++) s = s->next;
        while (s->next != NULL) {
            s = s->next;
            h = h->next;
        }
        s->next = head;
        head = h->next;
        h->next = NULL;
        return head;
    }
};