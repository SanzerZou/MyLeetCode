#include "mainheader.h"

int maxSubArray(vector<int>& nums) {
	int T = nums.size();
	int mx = INT_MIN;
	if (nums.empty())
		return 0;
	else if (T == 1){
		return nums[0];
	}
	for (int i = 1; i < T; i++){
		nums[i] += (nums[i - 1] > 0) ? nums[i - 1] : 0;
		if (nums[i] > mx){
			mx = nums[i];
		}
	}
	return mx;

}