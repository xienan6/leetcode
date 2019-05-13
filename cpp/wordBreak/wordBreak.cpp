// Source : https://leetcode.com/problems/copy-list-with-random-pointer/
// Author : Nan
// Date   : 2019-05-12
// Runtime: 32 ms

/*
* Use a hashmap to map old node to new node.       
*
* Time complexity O(n), Space complexity O(n)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(-1, NULL, NULL), *last = dummy, *p = NULL, *cur = head;
        unordered_map<Node*, Node*> m;
        while (cur) {
            p = new Node(cur->val, NULL, NULL);
            last->next = p;
            last = p;
            m[cur] = p;
            cur = cur->next;
        }
        cur = head;
        p = dummy->next;
        while (cur) {
            p->random = m[cur->random];
            p = p->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};