#include "mainheader.h"
/*
	������Ҫ����free ListNode������ʹ��delete����Ϊ��һ������ʹ��new�������ģ�

	����˼����ǣ���һ����ͬʱ���ƶ�ָ�룬����ֻ��������һ���ڵ㣬����ǳ�֮���
*/
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* cur = head;
	if (head == NULL)
		return head;
	while (cur->next != NULL){
		if (cur->val == cur->next->val)
			cur->next == cur->next->next;
		else
			cur = cur->next;
	}
	return head;
	
}