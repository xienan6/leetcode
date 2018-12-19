// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list
// Author : Nan
// Date   : 2018-12-19
// 208 / 208 test cases passed.
// Runtime: 4 ms

/*
* One pass algorithm. Use two pointers. One is from start and one is from Nth node. 
* Their gap is always n and when the second pointer is null, we can delete the node of first pointer.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head, *second = head, *last = head;
        for (int i = 0; i < n - 1; i++) second = second -> next;
        bool flag = true;
        while (second -> next != NULL) {
            last = first;
            first = first -> next;
            second = second -> next;
            flag = false;
        }
        if (last == head && flag) head = head -> next;
        else last -> next = first -> next;
        return head;
    }
};