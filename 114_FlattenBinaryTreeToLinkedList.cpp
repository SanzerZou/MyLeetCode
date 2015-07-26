#include "mainheader.h"
/*
	先拆那一段再拆哪一段是有讲究的
*/
void flatten(TreeNode* root) {
	TreeNode* cur = root;
	while (cur){
		TreeNode* pre = cur->left;
		// 核心是如何将左右的子链连接起来
		if (pre){
			while (pre->right) pre = pre->right;
			pre->right = cur->right;
			cur->right = cur->left;
			cur->left = NULL;
		}
		cur = cur->right;
	}
}