#include "mainheader.h"
#include <stack>

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	int na = 0;
	int nb = 0;
	// ����listA�ĳ���
	ListNode* cur = headA;
	while (cur){
		na++;
		cur = cur->next;
	}
	// ����listB�ĳ���
	cur = headB;
	while (cur){
		nb++;
		cur = cur->next;
	}
	// ����list���߲�ֵ����
	if (na >= nb){
		int i = na - nb;
		while (i--){
			headA = headA->next;
		}
	}
	else{
		int i = nb - na;
		while (i--){
			headB = headB->next;
		}
	}
	// ��ͬ�����ٶ���
	while (headA != headB && headA){
		headA = headA->next;
		headB = headB->next;
	}
	return headA;
}
// ʹ��ջʵ�֣�LIFO
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
	stack<ListNode*> sa;
	stack<ListNode*> sb;
	while (headA){
		sa.push(headA);
	}
	while (headB){
		sb.push(headB);
	}
	while (!sa.empty() && !sb.empty() && sa.top() != sb.top()){
		sa.pop();
		sb.pop();
	}
	if (sa.empty() || sb.empty())
		return NULL;
	else
		return sa.top();
}