#include "mainheader.h"
#include <algorithm>
/*
	��������̬�滮
	��һ��������¼һֱ���������ֵ��
	
	�����������������йأ����Ե�ǰ�����ֵ����Сֵ���������������й��׵ģ����Զ���Ҫ����

	�����ڴ���Ŀ����������ĳ˻������Ժ͵�ǰֵҲ���йصģ������Ŀ�Ķ�̬�滮������Ҫ��¼�ܶ�ֵ��ֻ��Ҫ��¼ǰһ��λ�õ�ֵ����
*/
int maxProduct(vector<int>& nums) {
	if (nums.empty())
		return 0;
	int minn = nums[0];
	int maxn = nums[0];
	int res = nums[0];
	for (int i = 1; i < nums.size(); i++){
		int a = maxn * nums[i];
		int b = minn * nums[i];

		maxn = max(max(a, b), nums[i]);
		minn = min(min(a, b), nums[i]);

		if (maxn > res)
			res = maxn;
	}
	return res;
}