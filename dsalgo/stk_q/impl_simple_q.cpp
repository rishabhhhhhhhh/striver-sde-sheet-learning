class Queue {
	int front, rear;
	vector<int> arr;

	bool isEmpty() {
		return front == rear;
	}

	public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	void enqueue(int e)
	{
		arr[rear] = e;
		rear++;
	}

	int dequeue()
	{
		if(isEmpty()) {
			return -1;
		}
		int ans = arr[front];
		front++;
		if(front == rear) {
			front = rear = 0;
		}
		return ans;
	}
};