#include "mainheader.h"
/*
	题目要求：特殊版的二分法查找，怎样将直观的情况缩减为较少的情况。
	二分法编程：
		1.独自实现递归法
		2.挑战，实现循环法
*/
int binarySearch(const vector<int>& nums, int lh, int rh,const int target){
	// 注意1：当左边大于右边时才退出循环，小于或等于都是继续执行
	if (lh > rh) return -1;
	// 注意2：左边加右边除以2，表示的是中点下界，这个概念非常重要
	int mid = (lh + rh) / 2;
	// 终止条件
	if (nums[mid] == target) return mid;
	// 注意3：由于是下界，所以拿中值与左值判断时是有可能相等的，所以是大于等于 “>=”
	// 注意4：由于只旋转的一次，所以也就多了一种情况，即中值的位置
	if (nums[mid] >= nums[lh]){
		// 注意5：target是有可能等于左值的，所以是大于等于号
		if (target < nums[mid] && target >= nums[lh])
			return binarySearch(nums, lh, mid - 1, target);
		else
			return binarySearch(nums, mid + 1, rh, target);
	}
	else{
		// 注意6：target是有可能等于右值的
		if (target > nums[mid] && target <= nums[rh])
			return binarySearch(nums, mid + 1, rh, target);
		else
			return binarySearch(nums, lh, mid - 1, target);
	}
}

int search(vector<int>& nums, int target) {
	int T = nums.size();
	int L = 0;
	int R = T - 1;
	if (target < nums[L] && target > nums[R])
		return -1;
	while (L <= R){
		int M = (L + R) / 2;
		if (nums[M] == target)
			return M;
		if (nums[M] >= nums[L]){
			if (target < nums[M] && target >= nums[L])
				R = M - 1;
			else
				L = M + 1;
		}
		else{
			if (target > nums[M] && target <= nums[R])
				L = M + 1;
			else
				R = M - 1;
		}
	}
	return -1;
}