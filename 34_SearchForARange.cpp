#include "mainheader.h"
/*
	�ҵķ������ҵ�targetȻ�����ұ����ұ߽硣���������ӶȽϸ�û�дﵽO(logn)
	���淽������ν��ж��ֲ���ң�ֱ���������ַ������ƺܺã���ʵ���Ӷ�Ҳͦ��
	����ķ���:���ַ��Һ����ҵ����Ͻ磬���Կ��Բ���(target - 0.5)��(target + 0.5)�������½�
*/

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> res;
	res.push_back(-1);
	res.push_back(-1);
	int T = nums.size();
	if (target < nums[0] || target > nums[T - 1]){
		return res;
	}
	int L = 0;
	int R = T - 1;
	int M = 0;
	while (L <= R){
		M = (L + R)/2;
		if (nums[M] == target)
			break;
		else if (target < nums[M])
		{
			R = M - 1;
			continue;
		}
		else{
			L = M + 1;
			continue;
		}
	}
	if (L > R){
		return res;
	}
	else{
		int i = M;
		int j = M;
		while (nums[i] == target)
		{
			i--;
			if (i < 0) break;
		}
		while (nums[j] == target)
		{
			j++;
			if (j > T - 1) break;
		}
		res.clear();
		res.push_back(i + 1);
		res.push_back(j - 1);
		return res;
	}
}