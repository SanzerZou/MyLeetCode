#include "mainheader.h"
/*
	ʹ�õݹ�ķ��������������
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* mergeTwoNode(ListNode* n1, ListNode* n2){
	// �߽�����������ֹ�ݹ�ĵط�
	if (n1 == NULL){
		return n2;
	}
	else if (n2 == NULL){
		return n1;
	}
	// �������зǳ��ʺ�ʹ�����ֵݹ�ķ�������Ϊ�з��ص�ֵ���Խ���ǰ�����ǰһ���������������
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