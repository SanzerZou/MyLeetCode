#include "mainheader.h"
/*
	������˼�룺Ѱ�� local maximum
	������ ���ַ�
	�����
		1.a[i] > a[i + 1];��i�����һ�����ڷ�ֵ��
		2.��֮ ��� a[i] < a[i + 1]; �� i + 1���ұ�һ�����ڷ�ֵ��
	����������ԣ����Կ���ʹ�ö��ַ���������
*/
int findPeakElement(vector<int>& nums) {
	int lh = 0;
	int rh = nums.size() - 1;
	while (lh < rh){
		int mid1 = (lh + rh) / 2;
		int mid2 = mid1 + 1; // ˼��Ϊʲôʹ��mid1 + 1����Ϊ���lh != rh,�� mid1 + 1 <= rh;
		if (nums[mid1] > nums[mid2]){
			rh = mid1;
		}
		else{
			lh = mid2;
		}
	}
	return lh;
}