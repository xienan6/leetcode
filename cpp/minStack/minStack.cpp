// Source : https://leetcode.com/problems/min-stack
// Author : Nan
// Date   : 2019-05-19
// Runtime: 24 ms

/*
* Use two stacks. One stack to store the pushed 
* data in order, and the other to store the minimum 
* value that has occurred.
*
* Time complexity O(1), Space complexity O(n)
*/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    
    }
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top()) s2.push(x);
    }
    
    void pop() {
        if (s1.top() == s2.top()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1, s2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */