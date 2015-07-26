#include "mainheader.h"
void isSymmetric(TreeNode* p, TreeNode* q, bool& flg){
	if (p == NULL && q == NULL)
		return;
	else if(p != NULL && q != NULL && p->val == q->val){
		isSymmetric(p->right, q->left, flg);
		isSymmetric(p->left, q->right, flg);
	}
	else
		flg = false;
}
bool isSymmetric(TreeNode* root) {
	bool flg = true;
	if (root == NULL)
		return flg;
	isSymmetric(root->left, root->right, flg);
	return flg;
}