/*
    You are given an array/list say ‘ARR’ of size ‘N’. We call pair (i, j) a Reverse Pair when i < j and 'ARR[i]' > 2 * 'ARR[j]'. Your task is to find the number of Reverse Pairs present in given 'ARR'.
*/
#include <bits/stdc++.h>
void mergeArr(
	vector<int> & arr,
	int left,
	int mid,
	int right,
	int & ans
) {
	int len = right - left + 1;
	vector<int> tempArr(len);
	int tempC = 0;

	int leftC = left, rightC = mid + 1;
	int counter = leftC;

	while(leftC <= mid && rightC <= right) {
		if(arr[leftC] <= arr[rightC])
			tempArr[tempC++] = arr[leftC++];
		else {
			while(counter <= mid && arr[counter] <= 2*arr[rightC])
				counter++;
			ans = ans + (mid - counter + 1);
			tempArr[tempC++] = arr[rightC++];
		}
	}

	while(leftC <= mid)
		tempArr[tempC++] = arr[leftC++];

	while(rightC <= right)
		tempArr[tempC++] = arr[rightC++];

	for(int i=left, j=0; j < len ; j++, i++)
		arr[i] = tempArr[j];
}

void merge_sort(vector<int> & arr, int left, int right, int & ans) {
	if(left < right) {
		int mid = (left + right) >> 1;
		merge_sort(arr, left, mid, ans);
		merge_sort(arr, mid+1, right, ans);
		mergeArr(arr, left, mid, right, ans);
	}
}

int reversePairs(vector<int> &arr, int n){
	int ans = 0;
	merge_sort(arr, 0, n-1, ans);
	return ans;
}