#include "mainheader.h"
/*
	并不需要考虑free ListNode，比如使用delete，因为不一定就是使用new所创建的；

	核心思想就是，下一个不同时才移动指针，否则只是跳过下一个节点，链表非常之灵活
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