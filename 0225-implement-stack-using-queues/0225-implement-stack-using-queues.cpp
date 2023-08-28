class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()!=1) {
            q2.push(q1.front());
            q1.pop();
        }
        int k=q1.front();
        q1.pop();
        queue<int> q=q1;
        q1=q2;
        q2=q;
        return k;
    }
    
    int top() {
        while(q1.size()!=1) {
            q2.push(q1.front());
            q1.pop();
        }
        int k=q1.front();
        q1.pop();
        q2.push(k);
        queue<int> q=q1;
        q1=q2;
        q2=q;
        return k;
    }
    
    bool empty() {
        return (q1.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */