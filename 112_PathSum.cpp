#include "mainheader.h"
bool sumPath(TreeNode* node, int sum){
	bool res = false;
	if (node->left == NULL && node->right == NULL){
		if (sum == node->val)
			return true;
		else
			return false;
	}
	if (node->left != NULL)
		res = res || sumPath(node->left, sum - node->val);
	if (node->right != NULL)
		res = res || sumPath(node->right, sum - node->val);
	return res;
}
bool hasPathSum(TreeNode* root, int sum) {
	if (root == NULL)
		return false;
	return sumPath(root, sum);
}