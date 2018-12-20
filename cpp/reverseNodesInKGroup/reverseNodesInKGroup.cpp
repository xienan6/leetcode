// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author : Nan
// Date   : 2018-12-20
// 81 / 81 test cases passed.
// Runtime: 12 ms

/*
* simulate
*
* Time complexity O(n), Space complexity O(k)
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *prev_tail = dummy_head;
        while (true) {
            ListNode *next_head=prev_tail;
            stack<ListNode*> s;
            for (int i=0; i<k && next_head->next; i++) {
                next_head = next_head->next;
                s.push(next_head);
            }
            if (s.size() < k) break; // fewer than k remaining
            next_head = next_head->next;
            
            // reverse the k-group
            ListNode* n = prev_tail;
            while (!s.empty()) {
                n->next = s.top();
                n = s.top();
                s.pop();
            }
            n->next = next_head;
            prev_tail = n;
        }
        return dummy_head->next;
    }
};