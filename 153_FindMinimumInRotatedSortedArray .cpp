#include "mainheader.h"

int findMin(vector<int>& nums) {
	int lh = 0;
	int rh = nums.size() - 1;
	while (lh < rh){
		if (nums[lh] < nums[rh])
			return nums[lh];
		int mid = (lh + rh) / 2;
		if (nums[mid] >= nums[lh])
			lh = mid + 1;
		else
			rh = mid;
	}
	return nums[lh];
}