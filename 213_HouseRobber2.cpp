#include "mainheader.h"
#include <algorithm>
int rob(vector<int>& nums) {
	if (nums.empty())
		return 0;
	else if (nums.size() == 1)
		return nums[0];
	else if (nums.size() == 2)
		return max(nums[0], nums[1]);
	else if (nums.size() == 3)
		return max(max(nums[0], nums[2]), nums[1]);
	int pre1 = nums[0];
	int pro1 = max(nums[0], nums[1]);
	int pre2 = nums[1];
	int pro2 = max(nums[1], nums[2]);
	for (int i = 2; i < nums.size() - 1; i++){
		int tp = pro1;
		pro1 = max(pre1 + nums[i], pro1);
		pre1 = tp;
	}
	for (int i = 2; i < nums.size() - 1; i++){
		int tp = pro2;
		pro2 = max(pre2 + nums[i + 1], pro2);
		pre2 = tp;
	}
	return max(pro1, pro2);
}