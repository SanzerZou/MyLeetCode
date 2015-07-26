#include "mainheader.h"
#include <algorithm>

void dfsSub2(vector<vector<int>>& res, vector<int> &inv, vector<int> outv, int s){
	for (int i = s; i < inv.size();){
		int tp = inv[i];
		outv.push_back(tp);
		res.push_back(outv);
		dfsSub2(res, inv, outv, i + 1);
		outv.pop_back();
		while (i < inv.size() && tp == inv[i])
			i++;
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	int T = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	res.push_back(vector<int>());
	dfsSub2(res, nums, vector<int>(), 0);
	return res;
}