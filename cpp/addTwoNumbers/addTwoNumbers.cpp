// Source : https://oj.leetcode.com/problems/two-sum/
// Author : Nan
// Date   : 2018-12-05
// 1563 / 1563 test cases passed.
// Runtime: 36 ms

/*
* Normal addition is achieved by two linked lists from low postion 
* to high positon. You can use a variable to recording carry.  
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ll1 = l1;
        ListNode *ll2 = l2;
        ListNode *result = NULL;
        ListNode *p;
        int sum, carry = 0;
        while (ll1 != NULL || ll2 != NULL || carry != 0) {
            sum = 0;
            if (ll1 != NULL) {
                sum += ll1->val;
                ll1 = ll1->next;
            }
            if (ll2 != NULL) {
                sum += ll2->val;
                ll2 = ll2->next;
            }
            sum += carry ;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *newNode = new ListNode(sum);
            if (result == NULL) {
                result = newNode;
                p = newNode;
            } else {
                p->next = newNode;
                p = p->next;
            }
        }
        return result;
    }
};