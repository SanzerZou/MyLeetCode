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
	// ���������������ɾ��ͷָ���ʱ��
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