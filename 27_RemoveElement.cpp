#include "mainheader.h"
#include <algorithm>
/*
	学习到的知识：
		1.sort的使用，参数是iterator指代区间
		2.find的使用，参数是iterator与查找的值
		3.erase的使用，参数是iterator指代查找区间
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