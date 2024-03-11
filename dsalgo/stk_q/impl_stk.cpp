class Stack {
    vector<int> arr;
    int size;
    int topIndex;

    public:
    
    Stack(int capacity) {
        size = capacity;
        arr.insert(arr.begin(), size, 0);
        topIndex = -1;
    }

    void push(int num) {
        if(!isFull()) {
            arr[topIndex + 1] = num;
            topIndex++;
        }
    }

    int pop() {
        if(isEmpty())
            return -1;
        int ans = arr[topIndex];
        topIndex--;
        return ans;
    }
    
    int top() {
        if(isEmpty())
            return -1;
        return arr[topIndex];
    }
    
    int isEmpty() {
        return topIndex == -1;
    }
    
    int isFull() {
        return topIndex == size - 1;
    }  
};
