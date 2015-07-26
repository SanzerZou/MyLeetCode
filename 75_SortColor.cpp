#include "mainheader.h"
/*
	����ֻ������������Կ����ü��������������ַ�����Ҫ�����������飬һ�μ�����һ�θ�ֵ

	����һ�����������two point��ָ�����ֵ����Сֵ��Ȼ��ʹ��swap������������ֵ
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
// ����2��
void sortColors2(vector<int>& nums) {
	int l = 0;
	int r = nums.size() - 1;
	for (int i = 0; i <= r; i++){
		if (nums[i] == 0) swap(nums[i], nums[l++]);
		// ע�⣺��2�û�������ֵ�п����� 0�����Բ���ֱ��++��Ҫ��-- ���е���
		else if (nums[i] == 2) swap(nums[i--], nums[r--]);
	}
}

//int main(){
//	vector<int> inv = { 1, 1, 0, 2, 1, 2, 0 };
//	sortColors2(inv);
//	return 0;
//}