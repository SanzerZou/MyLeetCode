#include "mainheader.h"
/*
	��ĿҪ�������Ķ��ַ����ң�������ֱ�۵��������Ϊ���ٵ������
	���ַ���̣�
		1.����ʵ�ֵݹ鷨
		2.��ս��ʵ��ѭ����
*/
int binarySearch(const vector<int>& nums, int lh, int rh,const int target){
	// ע��1������ߴ����ұ�ʱ���˳�ѭ����С�ڻ���ڶ��Ǽ���ִ��
	if (lh > rh) return -1;
	// ע��2����߼��ұ߳���2����ʾ�����е��½磬�������ǳ���Ҫ
	int mid = (lh + rh) / 2;
	// ��ֹ����
	if (nums[mid] == target) return mid;
	// ע��3���������½磬��������ֵ����ֵ�ж�ʱ���п�����ȵģ������Ǵ��ڵ��� ��>=��
	// ע��4������ֻ��ת��һ�Σ�����Ҳ�Ͷ���һ�����������ֵ��λ��
	if (nums[mid] >= nums[lh]){
		// ע��5��target���п��ܵ�����ֵ�ģ������Ǵ��ڵ��ں�
		if (target < nums[mid] && target >= nums[lh])
			return binarySearch(nums, lh, mid - 1, target);
		else
			return binarySearch(nums, mid + 1, rh, target);
	}
	else{
		// ע��6��target���п��ܵ�����ֵ��
		if (target > nums[mid] && target <= nums[rh])
			return binarySearch(nums, mid + 1, rh, target);
		else
			return binarySearch(nums, lh, mid - 1, target);
	}
}

int search(vector<int>& nums, int target) {
	int T = nums.size();
	int L = 0;
	int R = T - 1;
	if (target < nums[L] && target > nums[R])
		return -1;
	while (L <= R){
		int M = (L + R) / 2;
		if (nums[M] == target)
			return M;
		if (nums[M] >= nums[L]){
			if (target < nums[M] && target >= nums[L])
				R = M - 1;
			else
				L = M + 1;
		}
		else{
			if (target > nums[M] && target <= nums[R])
				L = M + 1;
			else
				R = M - 1;
		}
	}
	return -1;
}