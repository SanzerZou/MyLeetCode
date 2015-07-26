#include "mainheader.h"
/*
	￥核心思想：寻找 local maximum
	方法： 二分法
	如果：
		1.a[i] > a[i + 1];则i的左边一定存在峰值；
		2.反之 如果 a[i] < a[i + 1]; 则 i + 1的右边一定存在峰值；
	由于这个特性，所以可以使用二分法进行收敛
*/
int findPeakElement(vector<int>& nums) {
	int lh = 0;
	int rh = nums.size() - 1;
	while (lh < rh){
		int mid1 = (lh + rh) / 2;
		int mid2 = mid1 + 1; // 思考为什么使用mid1 + 1，因为如果lh != rh,则 mid1 + 1 <= rh;
		if (nums[mid1] > nums[mid2]){
			rh = mid1;
		}
		else{
			lh = mid2;
		}
	}
	return lh;
}