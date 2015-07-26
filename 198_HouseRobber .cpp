#include "mainheader.h"
#include <algorithm>
/*
	��̬�滮���ù�ȥ����Ϣ�����ڵ�ֵ
	˼�������ڵ�״̬�������ȥ����״̬��أ�
	���������ֵ���б��棻
*/
int rob2(vector<int>& nums) {
	// �߽������ж�
	if (nums.empty())
		return 0;
	int T = nums.size();
	if (T == 1)
		return nums[0];
	else if (T == 2)
		return max(nums[0], nums[1]);
	vector<int> res(T, 0);
	// ������ʼ��
	nums[0] = nums[0];
	nums[1] = max(nums[0], nums[1]);
	// ����ÿ�����ֵ���ڴ��ظ�����
	for (int i = 2; i < T; i++){
		res[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
	}
	return res[T - 1];
}