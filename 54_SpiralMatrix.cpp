#include "mainheader.h"

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	int rBegin = 0;
	int rEnd = matrix.size() - 1;
	int cBegin = 0;
	int cEnd = matrix[0].size() - 1;
	
	while (rBegin <= rEnd && cBegin <= cEnd){
		// row -> ��
		for (int j = cBegin; j <= cEnd; j++){
			res.push_back(matrix[rBegin][j]);
		}
		rBegin++;
		// col -> ��
		for (int j = rBegin; j <= rEnd; j++){
			res.push_back(matrix[j][cEnd]);
		}
		cEnd--;
		// row -> ��
		if (rBegin <= rEnd){
			for (int j = cEnd; j >= cBegin; j--){
				res.push_back(matrix[rEnd][j]);
			}
			rEnd--;
		}
		// col -> ��
		if (cBegin <= cEnd){
			for (int j = rEnd; j >= rBegin; j--){
				res.push_back(matrix[j][cBegin]);
			}
			cBegin++;
		}		
	}

	return res;
}