#include "mainheader.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
	int nn = n;
	ListNode *root = head;
	ListNode *node = head;
	ListNode *nextNode = head;
	while (nn--){
		nextNode = nextNode->next;
	}
	// 考虑特殊情况，当删除头指针的时候
	if (nextNode == NULL){
		root = root->next;
		delete head;
	}
	else{
		while (nextNode->next != NULL){
			node = node->next;
			nextNode = nextNode->next;
		}
		ListNode *tp = node->next;
		node->next = node->next->next;
		delete tp;
	}
	return root;
}