#include"mainheader.h"
void levelOrder(vector<vector<int>>& res, vector<TreeNode*> tp){
	vector<TreeNode*> mvt;
	vector<int> mvi;
	if (tp.empty())
		return;
	for (int i = 0; i < tp.size(); i++){
		mvi.push_back(tp[i]->val);
		if (tp[i]->left != NULL) mvt.push_back(tp[i]->left);
		if (tp[i]->right != NULL) mvt.push_back(tp[i]->right);
	}
	levelOrder(res, mvt);
	res.push_back(mvi);
}
vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> res;
	vector<TreeNode*> tp;
	if (root == NULL) return res;
	tp.push_back(root);
	levelOrder(res, tp);
	return res;
}