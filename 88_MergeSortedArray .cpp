#include "mainheader.h"
/*
	����˼�룺
		1.�ҵ��뷨�ǽ�������ֵ���ﵽ�����Ŀ�ġ�
		2.��ʵ������ڿհ׵ĵط���ʼ��ǰ���
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (m == 0){
		nums1 = nums2;
		return;
	}
	else if (n == 0) return;
	int idx1 = m - 1;
	int idx2 = n - 1;
	int idx = m + n - 1;
	while (idx1 >= 0 && idx2 >= 0){
		if (nums2[idx2] > nums1[idx1]){
			nums1[idx--] = nums2[idx2--];
		}
		else
			nums1[idx--] = nums1[idx1--];
	}
	while (idx2 > -1)
		nums1[idx--] = nums2[idx2--];
}

//int main(){
//	vector<int> inv1 = { 1, 0 };
//	vector<int> inv2 = { 2 };
//	merge(inv1, 1, inv2, 1);
//	return 0;
//}