#include "mainheader.h"
void sumNumbers(int& res, int tp, TreeNode* root){
	if (!root->left && !root->right){
		res += 10*tp + root->val;
		return;
	}
	if (root->left)
		sumNumbers(res,tp * 10 + root->val, root->left);
	if (root->right)
		sumNumbers(res, tp * 10 + root->val, root->right);
}
int sumNumbers(TreeNode* root) {
	if (!root)
		return 0;
	int res = 0;
	sumNumbers(res, 0, root);
	return res;
}

//int main(){
//	TreeNode root(0);
//	TreeNode leaft(1);
//	root.left = &leaft;
//	int res = sumNumbers(&root);
//	return res;
//}