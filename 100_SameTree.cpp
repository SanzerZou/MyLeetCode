#include "mainheader.h"
void isSameNode(TreeNode* p, TreeNode* q, bool& flg){
	if (p == NULL && q == NULL)
		return;
	else if (p != NULL && q != NULL && p->val == q->val){
		isSameNode(p->left, q->left, flg);
		isSameNode(p->right, q->right, flg);
	}
	else
		flg = false;
}
bool isSameTree(TreeNode* p, TreeNode* q) {
	bool flg = true;
	isSameNode(p, q, flg);
	return flg;
}