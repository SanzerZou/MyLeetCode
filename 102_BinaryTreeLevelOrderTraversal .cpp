#include "mainheader.h"
#include <queue>
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> res;
	queue<TreeNode*> mq;
	mq.push(root);
	while (!mq.empty()){
		vector<int> tp;
		for (int i = 0, n = mq.size(); i < n; i++){
			tp.push_back(mq.front()->val);
			if (mq.front()->left != NULL) mq.push(mq.front()->left);
			if (mq.front()->right != NULL) mq.push(mq.front()->right);
			mq.pop();
		}
		res.push_back(tp);
	}
	return res;
}