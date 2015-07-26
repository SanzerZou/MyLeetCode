#include "mainheader.h"
/*
	如何给二维vector初始化;
	使用匿名构造函数；
*/
int uniquePaths(int m, int n) {
	vector<vector<int>> res(m, vector<int>(n));
	if (res.empty())
		return 0;
	res[0] = vector<int>(n, 1);
	for (int i = 0; i < m; i++){
		res[i][0] = 1;
	}
	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; j++){
			res[i][j] = res[i][j - 1] + res[i - 1][j];
		}
	}
	return res[m - 1][n - 1];
}