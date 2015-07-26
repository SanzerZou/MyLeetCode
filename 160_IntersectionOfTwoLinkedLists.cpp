#include "mainheader.h"
#include <stack>

using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	int na = 0;
	int nb = 0;
	// 计数listA的长度
	ListNode* cur = headA;
	while (cur){
		na++;
		cur = cur->next;
	}
	// 技术listB的长度
	cur = headB;
	while (cur){
		nb++;
		cur = cur->next;
	}
	// 长的list先走差值步数
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
	// 以同样的速度走
	while (headA != headB && headA){
		headA = headA->next;
		headB = headB->next;
	}
	return headA;
}
// 使用栈实现，LIFO
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