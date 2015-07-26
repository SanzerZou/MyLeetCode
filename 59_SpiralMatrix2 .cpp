#include "mainheader.h"

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> res(n, vector<int>(n));
	// 方向数组，改变[x][y]
	if (n == 0){
		return res;
	}
	else if (n == 1){
		res[0][0] = 1;
		return res;
	}
	// 如游戏一般，方向控制横纵坐标
	const int dir[4][2] = { { 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 } };
	// 行列步长
	int r = n;
	int c = n;
	// 表示方向
	int d = 0;
	// 填充值
	int count = n;
	// 坐标
	int x = 0;
	int y = n - 1;
	int max = n*n;
	for (int i = 1; i <= n; i++){
		res[0][i - 1] = i;
	}
	while (true){
		for (int j = 1; j < c; j++){
			count++;
			x += dir[d][0];
			y += dir[d][1];
			res[x][y] = count;
		}
		if (count == max)
			break;
		d = (d + 1)%4;

		c--;
		swap(c, r);
	}
	return res;
}