class MyQueue {
public:
    stack<int> mainStack, helperStack;
    int peekValue = -1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if (peekValue == -1) peekValue = x;
        mainStack.push(x);
    }
    
    int pop() {
        while(!mainStack.empty()) {
            helperStack.push(mainStack.top());
            mainStack.pop();
        }
        int y = helperStack.top(); helperStack.pop();
        peekValue = -1;
        while(!helperStack.empty()) {
            mainStack.push(helperStack.top());
            if (peekValue == -1) peekValue = helperStack.top();
            helperStack.pop();
        }
        return y;
    }
    
    int peek() {
        return peekValue;
    }
    
    bool empty() {
        return mainStack.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */