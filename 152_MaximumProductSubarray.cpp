#include "mainheader.h"
#include <algorithm>
/*
	方法：动态规划
	用一个变量记录一直以来的最大值。
	
	由于最大乘数与正负有关，所以当前的最大值与最小值对求最大乘数都是有贡献的，所以都需要保存

	又由于此题目求得是连续的乘积，所以和当前值也是有关的，这个题目的动态规划并不需要记录很多值，只需要记录前一个位置的值即可
*/
int maxProduct(vector<int>& nums) {
	if (nums.empty())
		return 0;
	int minn = nums[0];
	int maxn = nums[0];
	int res = nums[0];
	for (int i = 1; i < nums.size(); i++){
		int a = maxn * nums[i];
		int b = minn * nums[i];

		maxn = max(max(a, b), nums[i]);
		minn = min(min(a, b), nums[i]);

		if (maxn > res)
			res = maxn;
	}
	return res;
}