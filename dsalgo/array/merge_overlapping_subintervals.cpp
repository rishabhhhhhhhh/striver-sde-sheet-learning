vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	sort(arr.begin(), arr.end());
	int left = INT_MIN, right = INT_MIN;
	vector< vector<int> > ans;
	for(vector< vector<int> >::iterator it = arr.begin() ; it != arr.end() ; it++) {
		int lRange = (*it)[0];
		int rRange = (*it)[1];
		if(lRange <= right)
			right = max(right, rRange);
		else {
			if(left != INT_MIN)
				ans.push_back({left, right});
			left = lRange;
			right = rRange;
		}
	}
	if(left != INT_MIN)
		ans.push_back({left, right});
	return ans;
}