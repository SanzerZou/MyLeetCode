#include "mainheader.h"
#include <queue>
/*
	使用队列实现，广度优先
*/
int minDepth(TreeNode* root) {
	if (root == NULL)
		return 0;
	queue<TreeNode*> mq;
	mq.push(root);
	int cnt = 0;
	bool flg = false;
	while (!mq.empty() && !flg){
		int T = mq.size();
		while (T--){
			TreeNode* tp = mq.front();
			if (tp->left == NULL && tp->right == NULL){
				flg = true;
				break;
			}
			else{
				if (tp->left != NULL) mq.push(tp->left);
				if (tp->right != NULL) mq.push(tp->right);
			}
			mq.pop();
		}
		cnt++;
	}
	return cnt;
}

//int main(){
//	TreeNode mt(0);
//	int res = minDepth(&mt);
//	return 0;
//}