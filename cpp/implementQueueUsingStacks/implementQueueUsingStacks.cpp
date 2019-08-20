// Source : https://leetcode.com/problems/implement-queue-using-stacks/
// Author : Nan
// Date   : 2019-08-20
// Runtime: 0 ms

/*
* Use two stacks.   
*
* Time complexity O(n), Space complexity O(n)
*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> s2;
        int n = s1.size();
        for (int i = 0; i < n - 1; ++i) {
            int s = s1.top();
            s1.pop();
            s2.push(s);
        }
        int res = s1.top();
        s1.pop();
        for (int i = 0; i < n - 1; ++i) {
            int s = s2.top();
            s2.pop();
            s1.push(s);
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> s2;
        int n = s1.size();
        for (int i = 0; i < n - 1; ++i) {
            int s = s1.top();
            s1.pop();
            s2.push(s);
        }
        int res = s1.top();
        for (int i = 0; i < n - 1; ++i) {
            int s = s2.top();
            s2.pop();
            s1.push(s);
        }
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
private:
    stack<int> s1;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */