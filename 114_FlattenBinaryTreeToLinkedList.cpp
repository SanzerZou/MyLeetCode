#include "mainheader.h"
/*
	�Ȳ���һ���ٲ���һ�����н�����
*/
void flatten(TreeNode* root) {
	TreeNode* cur = root;
	while (cur){
		TreeNode* pre = cur->left;
		// ��������ν����ҵ�������������
		if (pre){
			while (pre->right) pre = pre->right;
			pre->right = cur->right;
			cur->right = cur->left;
			cur->left = NULL;
		}
		cur = cur->right;
	}
}