#include "mainheader.h"

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> res(n, vector<int>(n));
	// �������飬�ı�[x][y]
	if (n == 0){
		return res;
	}
	else if (n == 1){
		res[0][0] = 1;
		return res;
	}
	// ����Ϸһ�㣬������ƺ�������
	const int dir[4][2] = { { 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 } };
	// ���в���
	int r = n;
	int c = n;
	// ��ʾ����
	int d = 0;
	// ���ֵ
	int count = n;
	// ����
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