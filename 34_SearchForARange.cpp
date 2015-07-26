#include "mainheader.h"
/*
	我的方法：找到target然后左右遍历找边界。最差情况复杂度较高没有达到O(logn)
	常规方法：多次进行二分差查找，直到收敛这种方法看似很好，其实复杂度也挺高
	巧妙的方法:二分法找核心找的是上界，所以可以查找(target - 0.5)和(target + 0.5)来找上下界
*/

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> res;
	res.push_back(-1);
	res.push_back(-1);
	int T = nums.size();
	if (target < nums[0] || target > nums[T - 1]){
		return res;
	}
	int L = 0;
	int R = T - 1;
	int M = 0;
	while (L <= R){
		M = (L + R)/2;
		if (nums[M] == target)
			break;
		else if (target < nums[M])
		{
			R = M - 1;
			continue;
		}
		else{
			L = M + 1;
			continue;
		}
	}
	if (L > R){
		return res;
	}
	else{
		int i = M;
		int j = M;
		while (nums[i] == target)
		{
			i--;
			if (i < 0) break;
		}
		while (nums[j] == target)
		{
			j++;
			if (j > T - 1) break;
		}
		res.clear();
		res.push_back(i + 1);
		res.push_back(j - 1);
		return res;
	}
}