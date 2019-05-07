// Source : https://leetcode.com/problems/linked-list-cycle-ii/
// Author : Nan
// Date   : 2019-05-06
// Runtime: 12 ms

/*
* Use a one-step slow pointer and a two-step fast pointer. 
* Slow pointer walk at most n steps when linked list itself 
* is a cycle. Notice the list has two same quantity.
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};