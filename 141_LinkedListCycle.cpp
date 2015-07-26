#include "mainheader.h"
#include <unordered_set>
/*
	����һ��ʹ��һ��ָ��set������Ѿ���㣬�������������Ľڵ�������ѭ��
*/
bool hasCycle(ListNode *head) {
	unordered_set<ListNode*> mset;
	while (head){
		if (mset.find(head) != mset.end()){
			return true;
		}
		else{
			mset.insert(head);
		}
		head = head->next;
	}
	return false;
}
/*
	�������������ָ�룬һ���죬һ������������ڻ������ָ��һ��������ָ������
	֤������ָ����Ƚ��뻷������ָ����뻷ʱ��ÿһ����ָ�붼�����һ�����������ջ�����
*/
bool hasCycle2(ListNode *head){
	ListNode* a = head;
	ListNode* b = head;
	while (a && b && b->next){
		if (a == b)
			return true;
		else{
			a = a->next;
			b = b->next->next;
		}
	}
	return false;
}