#include "mainheader.h"
#include <algorithm>
/*
	backtracking:���ݷ��Լ��Ͻ��б���
		1.˼�����ݷ����������
		2.�ǵöԼ��Ͻ�������
*/

void dfsCS(vector<vector<int>>& res,const vector<int>& candidates, vector<int> tp, int st, int target){
	for (int i = st; i < candidates.size(); i++){
		if (candidates[i] < target){
			// ��pushback����ʱ��popback�������Ͳ���Ҫ�����¹���һ��vector���ǳ�֮��������
			// ����˼���ǣ��ݹ�ʱ���ܸı䱾�ε����еĲ������ı�ʱ����Ҫ�ı������
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
