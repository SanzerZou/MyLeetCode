#include "mainheader.h"
/*
	链表问题一直是我的弱项，还是不能抽象的思考。
	学习到东西：
		1.链表问题，定义一个新结点，使首节点的问题也一般化。然后直接返还 start.next;
		2.命名问题，cur：当前指针，next1：下一个指针，next2：下两个指针。
		3.使用子函数及形参于返回参数来执行简单的重复操作使程序看起来更简洁，链表问题适合于这种返回函数型的方法。
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
ListNode* swapTwo(ListNode* next1, ListNode* next2){
	next1->next = next2->next;
	next2->next = next1;
	return next2;
}

ListNode* swapPairs(ListNode* head) {
	// 创建一个新节点使起始节点一般化，处理链表问题都可以这样处理。
	ListNode start(0);
	start.next = head;
	for (ListNode* cur = &start; cur->next != NULL && cur->next->next != NULL;cur = cur->next->next){
		cur->next = swapTwo(cur->next, cur->next->next);
	}
	return start.next;
}