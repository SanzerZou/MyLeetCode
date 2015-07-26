#include "mainheader.h"
#include <queue>
vector<int> rightSideView(TreeNode* root) {
	queue<TreeNode*> mq;
	vector<int> mv;
	if (!root)
		return mv;
	mq.push(root);
	while (!mq.empty()){
		mv.push_back(mq.front()->val);
		for (int i = mq.size(); i > 0; i--){
			if (mq.front()->right)
				mq.push(mq.front()->right);
			if (mq.front()->left)
				mq.push(mq.front()->left);
			mq.pop();
		}
	}
	return mv;
}