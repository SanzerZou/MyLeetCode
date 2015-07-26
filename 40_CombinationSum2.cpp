#include "mainheader.h"
#include <algorithm>

void dfsCS2(vector<vector<int>>& res, const vector<int>& candidates, vector<int> tp, int st, int target){
	for (int i = st; i < candidates.size(); i++){
		if (candidates[i] < target){
			// 先pushback返回时再popback，这样就不需要再重新构造一个vector，非常之聪明方法
			// 核心思想是，递归时不能改变本次迭代中的参数。改变时机的要改变回来。
			tp.push_back(candidates[i]);
			dfsCS2(res, candidates, tp, i + 1, target - candidates[i]);
			tp.pop_back();
			while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) ++i;
		}
		else if (candidates[i] == target){
			tp.push_back(candidates[i]);
			res.push_back(tp);
			tp.pop_back();
			return;
		}
		else
			return;
	}
}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> tp;
	sort(candidates.begin(), candidates.end());
	dfsCS2(res, candidates, tp, 0, target);
	return res;
}