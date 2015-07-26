#include "mainheader.h"
/*
	�������ܣ�������ʵ�ִ�����ӣ�����Ҳ��һ������
	ѧϰ����֪ʶ�� 
		1.������������������Ҫ�� ��ͷ����ǰ��㣬���½����
		2.����˼��ÿ���½�����Ժ���ĸ���
		3.�ڸ�ֵ�����ϣ��ܲ����ж����Ͳ����ж���䣬��ֱ��ʹ�� ��%���͡�/������
		4.ѧ��ʹ��whileִ��ѭ����䣬������ǳ���
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	// �߽������жϣ���������һ������Ϊ��
	if (l1 == NULL) return l2;
	else if (l2 == NULL) return l1;

	ListNode * resList = NULL;
	int carry = 0;
	ListNode * n1 = l1;
	ListNode * n2 = l2;
	// ˼��������Ϊʲô��Ҫ�����ڵ㣬��Ϊ��Ҫ����������������Ҫ֪����ǰ��㻹��Ҫ֪��ǰһ��㣬pNode��ʾǰһ��㣬pNext��ʾ��һ���
	ListNode * pNode = NULL;
	ListNode * pNext = NULL;
	while (n1 != NULL && n2 != NULL)
	{
		int sum = n1->val + n2->val + carry;
		carry = sum / 10;
		pNext = new ListNode(sum % 10);

		// ����ͷ���⴦��
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
	// ������������һ���������
	// ��������������ΪNULL����������
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
	//��������ΪNULLʱ�������Ĵ���
	if (carry != 0){
		pNext = new ListNode(carry);
		pNode->next = pNext;
		pNode = pNext;
	}
	
	return resList;
}