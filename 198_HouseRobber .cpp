#include "mainheader.h"
#include <algorithm>
/*
	动态规划即用过去的信息推现在的值
	思考，现在的状态到底与过去多少状态相关；
	将计算出的值进行保存；
*/
int rob2(vector<int>& nums) {
	// 边界条件判断
	if (nums.empty())
		return 0;
	int T = nums.size();
	if (T == 1)
		return nums[0];
	else if (T == 2)
		return max(nums[0], nums[1]);
	vector<int> res(T, 0);
	// 条件初始化
	nums[0] = nums[0];
	nums[1] = max(nums[0], nums[1]);
	// 计算每个点的值，内存重复利用
	for (int i = 2; i < T; i++){
		res[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
	}
	return res[T - 1];
}