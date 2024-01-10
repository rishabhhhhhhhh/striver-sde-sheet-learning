int removeDuplicates(vector<int> &arr, int n) {
	int ans = 0;
	int index = 0;
	while(index < n) {
		int element = arr[index];
		while(index < n && element == arr[index]) {
			index++;
		}
		ans++;
	}
	return ans;
}