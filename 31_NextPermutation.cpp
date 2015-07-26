#include "mainheader.h"
#include <algorithm>
void nextPermutation(vector<int>& nums) {
	if (nums.size() > 1){
		for (int i = nums.size()-1; i >= 0; i--){
			for (int j = nums.size()-1; i < j; j--){
				if (nums[i] < nums[j]){
					int tp = nums[i];
					nums[i] = nums[j];
					nums[j] = tp;
					reverse(nums.begin() + i + 1, nums.end());
					return;
				}
			}
		}
		sort(nums.begin(), nums.end());
		return;
	}
}