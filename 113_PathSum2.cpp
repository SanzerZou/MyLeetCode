#include "mainheader.h"
void dfs(vector<vector<int>>& res,vector<int> tp, TreeNode* node, int sum){
	// 应该先push 然后再计算是否满足条件
	tp.push_back(node->val);
	if (node->left == NULL && node->right == NULL){
		if (sum == node->val){
			res.push_back(tp);
			return;
		}
		else
			return;
	}
	if (node->left != NULL){
		dfs(res, tp, node->left, sum - node->val);
	}
	if (node->right != NULL){
		dfs(res, tp, node->right, sum - node->val);
	}
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> res;
	if (root == NULL)
		return res;
	dfs(res, vector<int>(), root, sum);
	return res;
}