#include "mainheader.h"
/*
	我的方法：使用额外空间进行赋值，多使用了很多空间，不够优

	更优的方法：使用两个指针，一个指示赋值值；另一个指示移动值
*/
int removeDuplicates(vector<int>& nums) {
	int T = nums.size();
	int sumCount = 0;
	int count = 0;
	vector<int> res;
	for (int i = 0; i < T;){
		int tp = nums[i];
		while (i < T && nums[i] == tp){
			i++;
			count++;
		}
		if (count < 3){
			sumCount += count;
			while (count--)
				res.push_back(tp);
		}
		else{
			sumCount += 2;
			res.push_back(tp);
			res.push_back(tp);
		}
		count = 0;
	}
	nums = res;
	return sumCount;
}
/*
	更优的算法
*/
int removeDuplicates2(int A[], int n, int k) {

	if (n <= k) return n;

	int i = 1, j = 1;
	int cnt = 1;
	while (j < n) {
		if (A[j] != A[j - 1]) {
			cnt = 1;
			A[i++] = A[j];
		}
		else {
			if (cnt < k) {
				A[i++] = A[j];
				cnt++;
			}
		}
		++j;
	}
	return i;
}

//int main(){
//	vector<int> inv = { 1, 1, 3, 3, 4, 6, 6, 6 };
//	int res = removeDuplicates(inv);
//	return 0;
//}