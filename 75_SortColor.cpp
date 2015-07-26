#include "mainheader.h"
/*
	由于只有三种情况所以可以用计数法，但是这种方法需要遍历两遍数组，一次计数，一次赋值

	还有一种巧妙方法，用two point，指代最大值与最小值，然后使用swap函数交换两个值
*/
void sortColors(vector<int>& nums) {
	int i = 0;
	int o = 0;
	int z = 0;
	int T = nums.size();
	for (int j = 0; j < T; j++){
		switch (nums[j])
		{
		case 0:
			o++;
			break;
		case 1:
			i++;
			break;
		case 2:
			z++;
			break;
		default:
			break;
		}
	}
	for (int j = 0; j < o; j++) nums[j] = 0;
	for (int j = o; j < o + i; j++) nums[j] = 1;
	for (int j = o + i; j < o + i + z; j++) nums[j] = 2;
}
// 方法2：
void sortColors2(vector<int>& nums) {
	int l = 0;
	int r = nums.size() - 1;
	for (int i = 0; i <= r; i++){
		if (nums[i] == 0) swap(nums[i], nums[l++]);
		// 注意：与2置换回来的值有可能是 0，所以不能直接++，要用-- 进行抵消
		else if (nums[i] == 2) swap(nums[i--], nums[r--]);
	}
}

//int main(){
//	vector<int> inv = { 1, 1, 0, 2, 1, 2, 0 };
//	sortColors2(inv);
//	return 0;
//}