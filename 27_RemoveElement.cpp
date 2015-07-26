#include "mainheader.h"
#include <algorithm>
/*
	ѧϰ����֪ʶ��
		1.sort��ʹ�ã�������iteratorָ������
		2.find��ʹ�ã�������iterator����ҵ�ֵ
		3.erase��ʹ�ã�������iteratorָ����������
*/

int removeElement(vector<int>& nums, int val) {
	sort(nums.begin(), nums.end());
	vector<int>::iterator it1 = find(nums.begin(), nums.end(), val);
	if (it1 != nums.end()){
		vector<int>::iterator it2 = it1;
		while (*it2 == *it1) {
			it2++;
			if (it2 == nums.end())
				break;
		}
		nums.erase(it1, it2);
	}
	return nums.size();
}