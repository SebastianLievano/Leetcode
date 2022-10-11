class MyQueue {
    private:
            stack<int> store;
        stack<int> move;
    
public:
    MyQueue() {
    }
    
    //ABC
    
    //CBA
    
    void push(int x) {
        store.push(x);
    }
    
    int pop() {
        while(!store.empty()){
            move.push(store.top());
            store.pop();
        }
        int val = move.top();
        move.pop();
        while(!move.empty()){
            store.push(move.top());
            move.pop();
        }
        return val;
    }
    
    int peek() {
        while(!store.empty()){
            move.push(store.top());
            store.pop();
        }
        int val = move.top();
        while(!move.empty()){
            store.push(move.top());
            move.pop();
        }
        return val;
    }
    
    bool empty() {
        return (store.empty());
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