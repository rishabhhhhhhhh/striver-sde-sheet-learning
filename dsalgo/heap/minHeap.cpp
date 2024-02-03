class MinHeap{
    int size;
    vector<int> arr;

    void heapifyTopDown(int index) {
        int leftChild = 2*index + 1;
        if(leftChild < size) {

            int leftVal = arr[leftChild];
            int rightChild = 2*index + 2;
            int rightVal = (rightChild < size) ? arr[rightChild] : INT_MAX;

            int minChild = leftVal < rightVal ? leftChild : rightChild;

            if(arr[index] > arr[minChild]) {
                swap(arr[index], arr[minChild]);
                heapifyTopDown(minChild);
            }
        }
    }

    void heapify(int index) {
        if(index <= 0)
            return;
        int parent = (index-1)/2;
        if(arr[parent] > arr[index])
            swap(arr[parent], arr[index]);
        heapify(parent);
    }

    public:
    MinHeap(){
        size = 0;
    }

    int getMin(){
        if(size == 0)
            return -1;
        int ans = arr[0];
        swap(arr[0], arr[size - 1]);
        
        arr.resize(size - 1);
        size--;

        heapifyTopDown(0);
        return ans;
    }

    bool insertElement(int data){
        size = size + 1;
        arr.push_back(data);
        heapify(size-1);
    }
};

vector<int> minHeap(int n, vector<vector<int>>& q) {
    MinHeap mHeap;
    vector<int> ans;
    for(int i=0;i<n;i++){
        vector<int> qL = q[i];
        if(qL[0] == 0)
            mHeap.insertElement(qL[1]);
        else
            ans.push_back(mHeap.getMin());
    }
    return ans;
}
