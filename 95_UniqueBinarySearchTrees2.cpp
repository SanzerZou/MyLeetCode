#include "mainheader.h"
/*
	有多种情况使用 vector 进行保存
*/
vector<TreeNode*> generateNode(int lh, int rh){
	vector<TreeNode*> v;
	if (lh > rh){
		v.push_back(NULL);
		return v;
	}
	else{
		for (int i = lh; i <= rh; i++){
			vector<TreeNode*> lv = generateNode(lh, i - 1);
			vector<TreeNode*> rv = generateNode(i + 1, rh);
			for (int m = 0; m < lv.size(); m++){
				for (int n = 0; n < rv.size(); n++){
					TreeNode* node = new TreeNode(i);
					node->left = lv[m];
					node->right = rv[n];
					v.push_back(node);
				}
			}
		}
	}
	return v;
}
vector<TreeNode*> generateTrees(int n) {
	vector<TreeNode*> res;
	res = generateNode(1, n);
	return res;
}