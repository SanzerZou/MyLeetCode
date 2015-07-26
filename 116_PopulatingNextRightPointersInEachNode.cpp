#include "mainheader.h"

void connect(TreeLinkNode *root) {
	if (root == NULL)
		return;
	TreeLinkNode* row;
	TreeLinkNode* col = root;
	while (col != NULL){
		for (row = col; row != NULL; row = row->next){
			row->left->next = row->right;
			row->right->next = (row->next == NULL)?NULL:row->next->left;
		}
		col = col->left;
	}
}