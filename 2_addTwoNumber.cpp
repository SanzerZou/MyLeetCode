#include "mainheader.h"
/*
	函数功能：用链表实现大数相加，返回也是一个链表
	学习到的知识： 
		1.处理链表必须得有三个要素 表头，当前结点，与新建结点
		2.认真思考每次新建结点以后结点的复制
		3.在赋值问题上，能不用判断语句就不用判断语句，而直接使用 ‘%’和‘/’符号
		4.学会使用while执行循环语句，这样会非常快
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	// 边界条件判断，即其中有一个链表为空
	if (l1 == NULL) return l2;
	else if (l2 == NULL) return l1;

	ListNode * resList = NULL;
	int carry = 0;
	ListNode * n1 = l1;
	ListNode * n2 = l2;
	// 思考：链表为什么需要两个节点，因为需要把链表链接起来需要知道当前结点还需要知道前一结点，pNode表示前一结点，pNext表示下一结点
	ListNode * pNode = NULL;
	ListNode * pNext = NULL;
	while (n1 != NULL && n2 != NULL)
	{
		int sum = n1->val + n2->val + carry;
		carry = sum / 10;
		pNext = new ListNode(sum % 10);

		// 链表头特殊处理
		if (resList == NULL){
			resList = pNode = pNext;
		}
		else
		{
			pNode->next = pNext;
			pNode = pNext;
		}
		n1 = n1->next;
		n2 = n2->next;
	}
	// 处理两个链表不一样长的情况
	// 将两个链表都处理为NULL后再做处理
	while (n1 != NULL){
		int sum = n1->val + carry;
		carry = sum / 10;
		pNext = new ListNode(sum % 10);
		pNode->next = pNext;
		pNode = pNext;
		n1 = n1->next;
	}
	while (n2 != NULL){
		int sum = n2->val + carry;
		carry = sum / 10;
		pNext = new ListNode(sum % 10);
		pNode->next = pNext;
		pNode = pNext;
		n2 = n2->next;
	}
	//当两个都为NULL时，所做的处理
	if (carry != 0){
		pNext = new ListNode(carry);
		pNode->next = pNext;
		pNode = pNext;
	}
	
	return resList;
}