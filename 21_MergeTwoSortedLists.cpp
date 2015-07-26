#include "mainheader.h"
/*
	初始想使用的方法是：选择其中一个链表作为基链表，另一个链表一个个的插入，但是这种方法复杂度高，需要频繁的断开和链接操作，time limitited
	改进方法：创建一个新的空链表头，然后再建一个指针灵活在两个链表之间游走，链接值较小的那个。最终处理为空的情况，结果为head
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	// 初始化链表，新建一个链表
	ListNode head(0);
	ListNode* iter = &head;
	// 核心代码
	while (l1 && l2){
		if (l1->val <= l2->val){
			// 链接
			iter->next = l1;
			// 放弃控制权
			l1 = l1->next;
		}
		else{
			iter->next = l2;
			l2 = l2->next;
		}
		// 取得控制权
		iter = iter->next;
	}
	iter->next = l1 ? l1 : l2;
	return head.next;
}
