#include "mainheader.h"

void rotate(vector<vector<int>>& matrix) {
	vector<vector<int>> matrix2(matrix);
	int T = matrix2[0].size();
	for (int i = 0; i < T; i++){
		for (int j = 0; j < T; j++){
			matrix2[j][T - i - 1] = matrix[i][j];
		}
	}
	matrix = matrix2;
}