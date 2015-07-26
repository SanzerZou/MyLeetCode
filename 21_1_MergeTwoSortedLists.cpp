#include "mainheader.h"
/*
	使用递归的方法，简便优美。
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* mergeTwoNode(ListNode* n1, ListNode* n2){
	// 边界条件，即终止递归的地方
	if (n1 == NULL){
		return n2;
	}
	else if (n2 == NULL){
		return n1;
	}
	// 在链表中非常适合使用这种递归的方法，因为有返回的值可以将当前结点与前一个结点链接起来。
	else if (n1->val < n2->val){
		n1->next = mergeTwoNode(n1->next, n2);
		return n1;
	}
	else{
		n2->next = mergeTwoNode(n1, n2->next);
		return n2;
	}
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
	ListNode* root = mergeTwoNode(l1, l2);
	return root;
}