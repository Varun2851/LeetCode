//https://leetcode.com/problems/min-stack/submissions/
class MinStack {
private:
    stack<int> s;
    int min = INT_MAX;
    
public:    
    MinStack() {        
    }
    
    void push(int val) {
        if(val <= min){
            s.push(min);    
            min = val;
        }        
        s.push(val);
    }
    
    void pop() {        
        if(s.top() == min) {
            s.pop();
            min = s.top();            
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min;
    }
};