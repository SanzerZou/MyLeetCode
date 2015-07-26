#include "mainheader.h"


ListNode* rotateRight(ListNode* head, int k) {
	ListNode *tail = head;
	if (head == NULL || head->next == NULL || k == 0)
		return head;
	int length = 1;
	while (tail->next != NULL){
		length++;
		tail = tail->next;
	}
	tail->next = head;
	k = k%length;	
	while (k--)
		tail = tail->next;
	head = tail->next;
	tail->next = NULL;
	return head;
}

//int main(){
//	ListNode one(1);
//	ListNode two(2);
//	ListNode three(3);
//	one.next = &two;
//	two.next = &three;
//	ListNode* res = rotateRight(&one, 2000000000);
//	return 0;
//}