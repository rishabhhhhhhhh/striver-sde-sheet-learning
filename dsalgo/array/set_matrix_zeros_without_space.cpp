#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	
	bool isFirstColZero = false;
	
	for(int row = 0 ; row < n ; row++) {
		if(matrix[row][0] == 0) {
			isFirstColZero = true;
			break;
		}
	}

	//setting row's 0
	for(int row  = 0 ; row < n ; row++) {

		bool isRowZero = false;

		for(int col = 0 ; col < m ; col++) {
			
			if(matrix[row][col] == 0) {

				isRowZero = true;
				break;
			}
		}

		if(isRowZero) {

			matrix[row][0] = 0;
		}
	}

	//setting col's 0
	for(int col = 1 ; col < m ; col++) {

		bool isColZero = false;
		for(int row = 0 ; row < n ; row++) {

			if(matrix[row][col] == 0) {

				isColZero = true;
				break;
			}
		}

		if(isColZero) {

			matrix[0][col] = 0;
		}
	}

	for(int row = 1; row < n ; row++) {

		for(int col = 1 ; col < m ; col++) {

			if(matrix[row][0] == 0 || matrix[0][col] == 0) {

				matrix[row][col] = 0;
			}
		}
	}

	if(matrix[0][0] == 0) {

		for(int col = 0 ; col < m ; col++) {
			matrix[0][col] = 0;
		}
	}

	if(isFirstColZero) {
		for(int row = 0 ; row < n ; row++) {
			matrix[row][0] = 0;
		}
	}

	return matrix;
}