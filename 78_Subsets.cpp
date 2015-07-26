#include "mainheader.h"
#include <algorithm>

void dfsSub(vector<vector<int>>& res, vector<int> &inv, vector<int> outv,int s){
	for (int i = s; i < inv.size(); i++){
		outv.push_back(inv[i]);
		res.push_back(outv);
		dfsSub(res, inv, outv, i + 1);
		outv.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	int T = nums.size();
	sort(nums.begin(), nums.end());
	vector<int> inv;
	for (int i = 0; i < T;){
		int tp = nums[i];
		inv.push_back(tp);
		// 记住不能超出范围
		while (i < T && nums[i] == tp )
			i++;
	}
	vector<vector<int>> res;
	res.push_back(vector<int>());
	dfsSub(res, inv, vector<int>(), 0);
	return res;
}
vector<vector<int> > subsets2(vector<int> &S) {
	sort(S.begin(), S.end());
	int elem_num = S.size();
	int subset_num = pow(2, elem_num);
	vector<vector<int> > subset_set(subset_num, vector<int>());
	for (int i = 0; i < elem_num; i++)
		for (int j = 0; j < subset_num; j++)
			if ((j >> i) & 1)
				subset_set[j].push_back(S[i]);
	return subset_set;
}

//int main(){
//	vector<int> inv = { 1, 2, 3, 1, 2,4,4};
//	vector<vector<int>> res = subsets(inv);
//	return 0;
//}