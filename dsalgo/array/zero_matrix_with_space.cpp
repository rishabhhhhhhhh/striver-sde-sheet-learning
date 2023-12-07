#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.

	vector<bool> row(n, false);
	vector<bool> col(m, false);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){

			if(matrix[i][j] == 0) {
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) {
			if(row[i] == true || col[j] == true) {
				matrix[i][j] = 0;
			}
		}
	}
	return matrix;
}