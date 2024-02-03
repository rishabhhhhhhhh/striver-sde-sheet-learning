vector<int> findMedian(vector<int> &arr, int n){
	
	priority_queue<int> maxPq;
	priority_queue< int, vector<int>, greater<int> > minPq;

	vector<int> ans;

	for(int i=0;i<n;i++){
		if(maxPq.size() == minPq.size()) {
			if(maxPq.size() == 0) {
				maxPq.push(arr[i]);
				ans.push_back(arr[i]);
			} else {
				int second = minPq.top();
				minPq.pop();

				if(second < arr[i]) {
					maxPq.push(second);
					minPq.push(arr[i]);
				} else {
					maxPq.push(arr[i]);
					minPq.push(second);
				}
				ans.push_back(maxPq.top());
			}
		} else {
			int second = maxPq.top();
			maxPq.pop();

			if(second < arr[i]) {
				maxPq.push(second);
				minPq.push(arr[i]);
			} else {
				maxPq.push(arr[i]);
				minPq.push(second);
			}
			ans.push_back((maxPq.top() + minPq.top())/2);
		}
	}
	return ans;
}
