#include "mainheader.h"
#include <algorithm>
int jump(vector<int>& nums) {
	int last = 0;
	int res = 0;
	int cur = 0;

	for (int i = 0; i < nums.size(); i++){
		if (i > last){
			last = cur;
			res++;
		}
		cur = max(cur, nums[i] + i);
	}

	return res;
}