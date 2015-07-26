#include "mainheader.h"
/*
	边界条件可以改为
	if(lh > rh) return NULL;
*/
TreeNode* arrayToBst(vector<int>& nums, int lh, int rh){
	TreeNode* node = new TreeNode(0);
	// 可以写为  lh + (rh - lh)/2避免overflow
	int mid = (lh + rh) / 2;
	node->val = nums[mid];
	if (lh == rh)
		return node;
	node->right = arrayToBst(nums, mid + 1, rh);
	if (lh == mid)
		return node;
	else
		node->left = arrayToBst(nums, lh, mid - 1);
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
	TreeNode* root;
	if (nums.empty()){
		return root;
	}
	else{
		return arrayToBst(nums, 0, nums.size() - 1);
	}
}