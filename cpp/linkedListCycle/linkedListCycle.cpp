// Source : https://leetcode.com/problems/linked-list-cycle/
// Author : Nan
// Date   : 2019-05-05
// Runtime: 20 ms

/*
* Use a one-step slow pointer and a two-step fast pointer. 
* Slow pointer walk at most n steps when linked list itself 
* is a cycle.
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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};