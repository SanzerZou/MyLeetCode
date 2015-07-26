#include "mainheader.h"
/*
	��������һֱ���ҵ�������ǲ��ܳ����˼����
	ѧϰ��������
		1.�������⣬����һ���½�㣬ʹ�׽ڵ������Ҳһ�㻯��Ȼ��ֱ�ӷ��� start.next;
		2.�������⣬cur����ǰָ�룬next1����һ��ָ�룬next2��������ָ�롣
		3.ʹ���Ӻ������β��ڷ��ز�����ִ�м򵥵��ظ�����ʹ������������࣬���������ʺ������ַ��غ����͵ķ�����
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
	// ����һ���½ڵ�ʹ��ʼ�ڵ�һ�㻯�������������ⶼ������������
	ListNode start(0);
	start.next = head;
	for (ListNode* cur = &start; cur->next != NULL && cur->next->next != NULL;cur = cur->next->next){
		cur->next = swapTwo(cur->next, cur->next->next);
	}
	return start.next;
}