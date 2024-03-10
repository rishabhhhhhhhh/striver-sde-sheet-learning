class MyStack {
    queue<int> q[2];
    int activeQ;
    
    void switchActiveQ() {
        activeQ = 1 - activeQ;
    }

    public:
    MyStack() {
        activeQ = 0;    
    }
    
    void push(int x) {
        q[activeQ].push(x);
    }
    
    int pop() {
       int ans;
        while(!q[activeQ].empty()) {
            ans = q[activeQ].front();
            q[activeQ].pop();
            if(q[activeQ].empty()){
                break;
            }
            q[1-activeQ].push(ans);
        }
        switchActiveQ();
        return ans;
    }
    
    int top() {
        int ans;
        while(!q[activeQ].empty()) {
            ans = q[activeQ].front();
            q[activeQ].pop();
            q[1-activeQ].push(ans);
        }
        switchActiveQ();
        return ans;
    }
    
    bool empty() {
        return q[activeQ].empty();
    }
};