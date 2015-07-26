#include "mainheader.h"
#include <algorithm>

/*
	�������ܣ�ʵ���ĸ�����ӵ���������
	�򵥷�������������Ӻ͵���target�ķ�����ͬ
*/
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	int nSize = nums.size();
	vector<vector<int>> res;
	vector<int> tp;
	if (nSize < 4){
		return res;
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nSize ;){
		for (int j = i + 1; j < nSize ;){
			int equal_2 = target - nums[i] - nums[j];
			int lh = j + 1;
			int rh = nSize - 1;
			while (rh > lh){
				if (nums[lh] + nums[rh] == equal_2){
					tp.push_back(nums[i]);
					tp.push_back(nums[j]);
					tp.push_back(nums[lh]);
					tp.push_back(nums[rh]);
					res.push_back(tp);
					// ȥ���ظ���ĸ
					while (lh < rh && nums[lh] == tp[2]) ++lh;
					while (lh < rh && nums[rh] == tp[3]) --rh;
					tp.clear();
				}
				else if (nums[lh] + nums[rh] > equal_2){
					rh--;
				}
				else{
					lh++;
				}
			}
			j++;
			// �ǵ�����ȥ��
			while (j < nSize && nums[j] == nums[j - 1]) 
				++j;
		}
		i++;
		while (i < nSize && nums[i] == nums[i - 1]) 
			++i;
	}
	return res;
}