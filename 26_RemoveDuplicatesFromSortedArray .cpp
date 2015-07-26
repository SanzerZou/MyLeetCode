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
	���Ӽ��Ĵ��룺�ӷ���˼���������ж�����ͬ����ĸ��n - count��Ϊ���
*/
/*
	int count = 0;
	for (int i = 1; i < n; i++){
		if (A[i] == A[i - 1]) count++;
		// ��ֵ���Ҳ�ر���
		else A[i - count] = A[i];
		}
	return n - count;
*/
