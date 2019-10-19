// Source : https://leetcode.com/problems/odd-even-linked-list/
// Author : Nan
// Date   : 2019-10-19
// Runtime: 16 ms

/*
* Use two pointers. One for odd nodes, and one for even nodes.
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head, *even = head->next, *even_head = head->next;
        while (even && even->next) {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = even_head;
        return head;
    }
};