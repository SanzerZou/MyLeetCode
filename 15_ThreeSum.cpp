#include "mainheader.h"
#include <cstdio>
#include <unordered_map>
#include <algorithm>
/*naive solution:我的方法
	复杂度:O(n^2*log(n))+log(n)
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> mnums = nums;
	// 排序
	sort(mnums.begin(), mnums.end());
	// 参数初始化
	int T = nums.size();
	for (int i = 0; i < T && mnums[i] <= 0; i++){
		for (int j = i + 1; j < T - 1 && mnums[j] <= (-mnums[i]); j++){
			int deta = - mnums[i] - mnums[j];
			if (binary_search(mnums.begin() + j + 1, mnums.end(), deta)){
				vector<int>::iterator it = find(mnums.begin() + j + 1, mnums.end(), deta);
				if (it != mnums.end()){
					while (*it == deta){
						vector<int> tp;
						tp.push_back(mnums[i]);
						tp.push_back(mnums[j]);
						tp.push_back(deta);
						res.push_back(tp);
						it++;
						if (it == mnums.end()){
							break;
						}
					}
				}
			}
		}
	}
	return res;
}

*/

/*
	better solution
	方法好在：
		1.复杂度绛到O(n^2)
		2.处理重复的可能出现的重复的结果
	学习到的知识：
		1.使用Algorithm的sort，与find方法，还有binary_search方法
		*2.两个指针左右移动
		3.使用while(ture)进行字母去重
		4.其实条件要考虑好，需要特殊处理
		5.有序以后问题就变得更好处理了
	我的方法：
		固定其中两个，然后搜索第三个数，由于第三个数我使用的是binary_search所以多了乘O(log(n))的复杂度
*/
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> mnums = nums;
	vector<int> tp;
	// 排序
	sort(mnums.begin(), mnums.end());
	// 参数初始化
	int T = mnums.size();

	for (int i = 0; mnums[i] <= 0 && i < T; i++){
		if (i == 0 || mnums[i] > mnums[i - 1]){
			int lh = i + 1;
			int rh = T - 1;
			int negate = -mnums[i];
			while (rh > lh){
				if (mnums[lh] + mnums[rh] == negate){
					tp.push_back(mnums[i]);
					tp.push_back(mnums[lh]);
					tp.push_back(mnums[rh]);
					res.push_back(tp);
					tp.clear();
					while (rh > lh && mnums[lh] == mnums[lh + 1]) lh++;
					while (rh > lh && mnums[rh] == mnums[rh - 1]) rh--;
					lh++;
					rh--;
				}
				else if (mnums[lh] + mnums[rh] > negate)
				{
					rh--;
				}
				else{
					lh++;
				}
			}
		}
	}
	return res;

}

