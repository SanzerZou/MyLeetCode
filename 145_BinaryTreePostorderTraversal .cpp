#include "mainheader.h"

void postorderTraversal(vector<int>& res, TreeNode* node){
	if (!node)
		return;
	postorderTraversal(res, node->left);
	postorderTraversal(res, node->right);
	res.push_back(node->val);
}
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> res;
	postorderTraversal(res, root);
	return res;
}