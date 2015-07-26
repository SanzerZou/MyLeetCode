#include "mainheader.h"

int searchInsert(vector<int>& nums, int target) {
	int T = nums.size();
	int L = 0;
	int R = T - 1;
	int M = 0;
	if (target < nums[0])
		return 0;
	else if (target > nums[T - 1])
		return T;
	while (L <= R){
		M = (L + R) / 2;
		if (nums[M] == target)
			return M;
		else if (target > nums[M]){
			L = M + 1;
		}
		else{
			R = M - 1;
		}
	}
	// 这个信息很重要，表示上界与下界
	if (L == M)
		return M;
	else if (R == M)
		return M + 1;
}