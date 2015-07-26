#include "mainheader.h"
#include <cstdio>
#include <unordered_map>
#include <algorithm>
/*naive solution:�ҵķ���
	���Ӷ�:O(n^2*log(n))+log(n)
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> mnums = nums;
	// ����
	sort(mnums.begin(), mnums.end());
	// ������ʼ��
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
	�������ڣ�
		1.���Ӷ�筵�O(n^2)
		2.�����ظ��Ŀ��ܳ��ֵ��ظ��Ľ��
	ѧϰ����֪ʶ��
		1.ʹ��Algorithm��sort����find����������binary_search����
		*2.����ָ�������ƶ�
		3.ʹ��while(ture)������ĸȥ��
		4.��ʵ����Ҫ���Ǻã���Ҫ���⴦��
		5.�����Ժ�����ͱ�ø��ô�����
	�ҵķ�����
		�̶�����������Ȼ�������������������ڵ���������ʹ�õ���binary_search���Զ��˳�O(log(n))�ĸ��Ӷ�
*/
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> mnums = nums;
	vector<int> tp;
	// ����
	sort(mnums.begin(), mnums.end());
	// ������ʼ��
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

