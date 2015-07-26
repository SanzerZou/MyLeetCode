#include "mainheader.h"
/*
	��ʼ��ʹ�õķ����ǣ�ѡ������һ��������Ϊ��������һ������һ�����Ĳ��룬�������ַ������Ӷȸߣ���ҪƵ���ĶϿ������Ӳ�����time limitited
	�Ľ�����������һ���µĿ�����ͷ��Ȼ���ٽ�һ��ָ���������������֮�����ߣ�����ֵ��С���Ǹ������մ���Ϊ�յ���������Ϊhead
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	// ��ʼ�������½�һ������
	ListNode head(0);
	ListNode* iter = &head;
	// ���Ĵ���
	while (l1 && l2){
		if (l1->val <= l2->val){
			// ����
			iter->next = l1;
			// ��������Ȩ
			l1 = l1->next;
		}
		else{
			iter->next = l2;
			l2 = l2->next;
		}
		// ȡ�ÿ���Ȩ
		iter = iter->next;
	}
	iter->next = l1 ? l1 : l2;
	return head.next;
}
