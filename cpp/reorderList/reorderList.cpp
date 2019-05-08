// Source : https://leetcode.com/problems/insertion-sort-list/
// Author : Nan
// Date   : 2019-05-07
// Runtime: 64 ms

/*
* Find the midpoint, cut the list and reverse the second 
* list. Then insert elements at intervals.
*
* Time complexity O(n), Space complexity O(n)
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        stack<ListNode*> st;
        ListNode *cur = head;
        while (cur) {
            st.push(cur);
            cur = cur->next;
        }
        int cnt = ((int)st.size() - 1) / 2;
        cur = head;
        while (cnt-- > 0) {
            auto t = st.top(); st.pop();
            ListNode *next = cur->next;
            cur->next = t;
            t->next = next;
            cur = next;
        }
        st.top()->next = NULL;
    }
};