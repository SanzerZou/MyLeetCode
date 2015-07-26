#include "mainheader.h"
void dfsPer(vector<vector<int>> &res, const vector<int>& nums
	,vector<int> tp, vector<bool> flg,int dp){
	if (dp == nums.size()){
		res.push_back(tp);
		return;
	}
	for (int i = 0; i < nums.size(); i++){
		if (!flg[i]){
			tp[dp] = nums[i];
			flg[i] = true;
			dfsPer(res, nums, tp, flg,dp + 1);
			flg[i] = false;
		}
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	int T = nums.size();
	vector<vector<int>> res;
	vector<int> tp(T, 0);
	vector<bool> flg(T, false);
	dfsPer(res, nums, tp, flg, 0);
	return res;
}