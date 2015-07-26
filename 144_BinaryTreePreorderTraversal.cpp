#include "mainheader.h"
void preorderTraversal(vector<int>& res, TreeNode* node){
	if (!node)
		return;
	res.push_back(node->val);
	preorderTraversal(res, node->left);
	preorderTraversal(res, node->right);
}
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	preorderTraversal(res, root);
	return res;
}