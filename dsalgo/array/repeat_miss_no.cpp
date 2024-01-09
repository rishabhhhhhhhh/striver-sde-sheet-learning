#include <bits/stdc++.h>

bool isFirstBitSet(int num1, int num2) {
	return num1 & num2;
}

int findFirstDifferentBit(int number) {

	int ans = 1;

	while(number > 0) {

		int d = number%2;
		if(d == 1) {
			return ans;
		}
		number = number >> 1;
		ans = ans << 1;
	}
}

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	
	int elementsXor = 0; //xor of missing no and repeat no
	int nElementsXor = 0;
	int arrayXor = 0;

	for(int i = 0 ; i < n ; i++) {

		arrayXor = arrayXor ^ arr[i];
		nElementsXor = nElementsXor ^ (i + 1);
	}

	elementsXor = arrayXor ^ nElementsXor;

	int firstDiffBit = findFirstDifferentBit(elementsXor);

	// cout << "Elements xor = " << elementsXor << endl;
	// cout << "First diff bit = " << firstDiffBit << endl;

	int group1 = 0;
	int group2 = 0;

	for(int i = 0 ; i < n ; i++) {

		if(isFirstBitSet(i + 1, firstDiffBit)) {
			group1 = group1 ^ (i + 1);
		} else {
			group2 = group2 ^ (i + 1);
		}

		if(isFirstBitSet(arr[i], firstDiffBit)) {
			group1 = group1 ^ arr[i];
		} else {
			group2 = group2 ^ arr[i];
		}
	}

	for(int i = 0 ; i < n ; i++) {

		if(arr[i] == group2) {

			return {
				group1,
				group2
			};
		} else if(arr[i] == group1) {

			return {
				group2,
				group1
			};
		}
	}
}
