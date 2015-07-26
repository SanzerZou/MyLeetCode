#include "mainheader.h"
#include <algorithm>
#include <queue>

void depth(TreeNode* node, int& maxdp, int dp){
	if (node == NULL)
		return;
	else{
		dp++;
		if (maxdp < dp)
			maxdp = dp;
		depth(node->left, maxdp, dp);
		depth(node->right, maxdp, dp);
	}
}

int maxDepth(TreeNode* root) {
	int maxdp = 0;
	depth(root, maxdp, 0);
	return maxdp;
}
/*
	方法二：递归
	从空节点往上数树，空节点贡献高度为零，其他节点往上加1
*/
int maxDepth2(TreeNode *root)
{
	return root == NULL ? 0 : max(maxDepth2(root->left), maxDepth2(root->right)) + 1;
}
/*
	广度优先，使用队列构造
*/
int maxDepth3(TreeNode *root)
{
	if (root == NULL)
		return 0;

	int res = 0;
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty())
	{
		++res;
		// ￥ 在进入循环时，先记录一下queue的大小，执行语句n次
		for (int i = 0, n = q.size(); i < n; ++i)
		{
			TreeNode *p = q.front();
			q.pop();

			if (p->left != NULL)
				q.push(p->left);
			if (p->right != NULL)
				q.push(p->right);
		}
	}
	return res;
}