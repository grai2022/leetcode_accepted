/*
https://leetcode.com/problems/min-stack/
*/

class MinStack {
    
private:
    stack<vector<int>> s;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        vector<int> t ;
        t.push_back(x);
        int min = !s.empty() ? s.top()[1] < x ?s.top()[1]: x : x;
        t.push_back(min);
        s.push(t);
        return;
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        if(s.empty()) return -1;
        return s.top()[0];
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return s.top()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
