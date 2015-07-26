#include "mainheader.h"

int removeDuplicates(vector<int>& nums) {
	if (nums.empty())
		return 0;
	int length = 1;
	int tmp = nums[0];
	int T = nums.size();
	for (int i = 0; i < T; i++){
		if (nums[i] == tmp){
			continue;
		}
		else{
			length++;
			tmp = nums[i];
			nums[length - 1] = tmp;
		}
	}
	return length;
}

/*
	更加简洁的代码：从反面思考，计算有多少相同的字母，n - count则为结果
*/
/*
	int count = 0;
	for (int i = 1; i < n; i++){
		if (A[i] == A[i - 1]) count++;
		// 赋值语句也特别赞
		else A[i - count] = A[i];
		}
	return n - count;
*/
