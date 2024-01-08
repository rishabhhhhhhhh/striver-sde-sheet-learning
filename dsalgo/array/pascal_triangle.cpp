vector<vector<int>> pascalTriangle(int N) {
    vector< vector<int> > matrix(N);

    for(int row = 0 ; row < N ; row++) {

        vector<int> colAns(row + 1);

        for(int col = 0 ; col <= row ; col++) {

            if(col == 0 || col == row) {

                colAns[col] = 1;
            } else {

                colAns[col] = matrix[row-1][col] + matrix[row-1][col-1];
            }
        }

        matrix[row] = colAns;
    }

    return matrix;
}