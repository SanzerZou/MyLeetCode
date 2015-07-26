#include "mainheader.h"

void rotate(vector<int>& nums, int k) {
	k %= nums.size();
	vector<int> tp(k, 0);
	tp.assign(nums.end() - k, nums.end());
	for (int i = nums.size() - k - 1; i >= 0; i--){
		nums[i + k] = nums[i];
	}
	for (int i = 0; i < k; i++){
		nums[i] = tp[i];
	}
}