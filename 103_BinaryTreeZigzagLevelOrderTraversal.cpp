#include "mainheader.h"
void zigzagOrder(vector<vector<int>>& res, vector<TreeNode*> tp, bool flg){
	vector<TreeNode*> mvt;
	vector<int> mvi;
	if (tp.empty())
		return;
	for (int i = 0; i < tp.size(); i++){
		mvi.push_back(tp[i]->val);
		if (tp[i]->left != NULL) mvt.push_back(tp[i]->left);
		if (tp[i]->right != NULL) mvt.push_back(tp[i]->right);
	}
	if (flg){
		reverse(mvi.begin(), mvi.end());
	}
	flg = !flg;
	res.push_back(mvi);
	zigzagOrder(res, mvt,flg);
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> res;
	vector<TreeNode*> tp;
	if (root == NULL) return res;
	tp.push_back(root);
	zigzagOrder(res, tp, false);
	return res;
}