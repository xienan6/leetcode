// Source : https://leetcode.com/problems/merge-k-sorted-lists/description/
// Author : Nan
// Date   : 2018-12-15
// 131 / 131 test cases passed.
// Runtime: 16 ms

/*
* Use a minimum heap or a priority queue to store first nodes in each list. 
* Insert a new node is O(logk) and get minimum is O(1).  
* You can also merge with divide dnd conquer. Time complexity is also O(nlogk). 
* But its constant may a little bigger than the first solutions.  
*
* Time complexity O(nlogk), Space complexity O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp {
    bool operator() (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                q.push(lists[i]);
            }
        }
        ListNode *head = NULL, *pre = NULL, *tmp = NULL;
        while (!q.empty()) {
            tmp = q.top();
            q.pop();
            if (pre != NULL) {
                pre->next = tmp;
            }
            else {
                head = tmp;
            }
            pre = tmp;
            if (tmp->next != NULL) {
                q.push(tmp->next);
            }
        }
        return head;
    }
};
