// Source : https://leetcode.com/problems/implement-stack-using-queues/
// Author : Nan
// Date   : 2019-07-17
// Runtime: 0 ms

/*
* Pop all and push all when push a new element.
*
* Time complexity O(n), Space complexity O(n)
*/

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            int t = q.front();
            q.push(t);
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = q.front();
        q.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private: 
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */