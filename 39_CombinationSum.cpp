#include "mainheader.h"
#include <algorithm>
/*
	backtracking:回溯法对集合进行遍历
		1.思考回溯法的输入参数
		2.记得对集合进行排序
*/

void dfsCS(vector<vector<int>>& res,const vector<int>& candidates, vector<int> tp, int st, int target){
	for (int i = st; i < candidates.size(); i++){
		if (candidates[i] < target){
			// 先pushback返回时再popback，这样就不需要再重新构造一个vector，非常之聪明方法
			// 核心思想是，递归时不能改变本次迭代中的参数。改变时机的要改变回来。
			tp.push_back(candidates[i]);
			dfsCS(res, candidates, tp, i, target - candidates[i]);
			tp.pop_back();
		}
		else if (candidates[i] == target){
			tp.push_back(candidates[i]);
			res.push_back(tp);
			return;
		}
		else
			return;
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> res;
	vector<int> tp;
	sort(candidates.begin(), candidates.end());
	dfsCS(res, candidates, tp, 0, target);
	return res;
}
