#include "mainheader.h"
/*
	我的方法：
		先查找列，再查找行，查找列时由于要比较当前列于后一列，可能会出现超出界限的情况，要判别处理好这种情况

	好的算法：
		将二维矩阵看作一维矩阵 m[i][j] = a[i*n + j] => a[x] = m[x/n][x%n]
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	int n = matrix[0].size();

	int low = 0;
	int hi = m - 1;
	int mid = 0;
	if (m > 1)
		while (low <= hi){
			mid = (hi + low) / 2;
			if (target < matrix[mid][0]){
				hi = mid - 1;
			}
			else{
				int mid_1 = (mid + 1 < m) ? matrix[mid + 1][0] : INT_MAX;
				if (target < mid_1){
					break;
				}
				else{
					low = mid + 1;
				}
			}
		}
	int lh = 0;
	int rh = n - 1;
	int mh;
	while (lh <= rh){
		mh = (lh + rh) / 2;
		if (target == matrix[mid][mh]){
			return true;
		}
		else if (target > matrix[mid][mh]){
			lh = mh + 1;
		}
		else
			rh = mh - 1;
	}
	return false;
}

//int main(){
//	vector<vector<int>> inv = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
//	bool res = searchMatrix(inv, 23);
//	return 0;
//}

/* 更加巧妙的方法
class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int n = matrix.size();
		int m = matrix[0].size();
		int l = 0, r = m * n - 1;
		while (l != r){
			int mid = (l + r - 1) >> 1;
			if (matrix[mid / m][mid % m] < target)
				l = mid + 1;
			else
				r = mid;
		}
	return matrix[r / m][r % m] == target;
	}
};
*/