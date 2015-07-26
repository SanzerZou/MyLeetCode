#include "mainheader.h"
void dfsInorder(vector<int>& res, TreeNode* node){
	if (node == NULL)
		return;
	dfsInorder(res, node->left);
	res.push_back(node->val);
	dfsInorder(res, node->right);
}
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	dfsInorder(res, root);
	return res;
}