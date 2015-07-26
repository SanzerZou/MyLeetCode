#include "mainheader.h"

void setZeroes(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size(); 
	vector<bool> fn(n, false);
	vector<bool> fm(m, false);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (matrix[i][j] == 0){
				fm[i] = true;
				fn[j] = true;
			}
		}
	}
	for (int i = 0; i < m; i++){
		if (fm[i]){
			matrix[i] = vector<int>(n, 0);
		}
	}
	for (int j = 0; j < n; j++){
		if (fn[j]){
			for (int i = 0; i < m; i++){
				matrix[i][j] = 0;
			}
		}
	}
}