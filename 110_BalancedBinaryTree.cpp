#include "mainheader.h"
#include <cmath>
#include <algorithm>
/*
	函数递归的返回参数是将和层级相关的参数作为返回值，而其他的参数则可以做为形参
	还有一些则可以做为临时变量。

	弱平衡树的定义：任意节点的左右子节点的深度差都不超过1。
*/
//void searchdp(TreeNode* node, int &min, int &max, int dp){
//	if (node->left == NULL && node->right == NULL){
//		min = (dp < min) ? dp : min;
//		max = (dp > max) ? dp : max;
//		return;
//	}
//	if (node->left == NULL)
//		min = (dp < min) ? dp : min;
//	else 
//		searchdp(node->left, min, max, dp + 1);
//	if (node->right == NULL)
//		min = (dp < min) ? dp : min;
//	else
//		searchdp(node->right, min, max, dp + 1);
//}
/*
	OverWirte:
*/
int deepth(TreeNode* node, bool& is_balance){
	if (node == NULL) return 0;
	int leftDp = deepth(node->left, is_balance);
	int rightDp = deepth(node->right, is_balance);
	if (abs(rightDp - leftDp) > 1) is_balance = false;
	if (!is_balance) return 0;
	return max(leftDp, rightDp) + 1;
}

bool isBalanced(TreeNode* root) {
	bool is_balance = true;
	deepth(root, is_balance);
	return is_balance;
}