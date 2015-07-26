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
	���������ݹ�
	�ӿսڵ������������սڵ㹱�׸߶�Ϊ�㣬�����ڵ����ϼ�1
*/
int maxDepth2(TreeNode *root)
{
	return root == NULL ? 0 : max(maxDepth2(root->left), maxDepth2(root->right)) + 1;
}
/*
	������ȣ�ʹ�ö��й���
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
		// �� �ڽ���ѭ��ʱ���ȼ�¼һ��queue�Ĵ�С��ִ�����n��
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