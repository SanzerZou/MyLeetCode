#include "mainheader.h"
#include <queue>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class CompareNode{
public:
	bool operator()(ListNode* const & a, ListNode* const & b) const{
		return a->val > b->val;
	}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
	// ���ȴ�����ͷ
	ListNode start(0);
	ListNode* cur = &start;
	// �������ȶ���
	priority_queue<ListNode*, vector<ListNode*>, CompareNode> mq;
	// Ϊ���ȶ������Ԫ��
	for (vector<ListNode*>::iterator it = lists.begin(); it < lists.end(); ++it){
		if (*it){
			mq.push(*it);
		}
	}
	// ����Ԫ��
	while (!mq.empty()){
		cur->next = mq.top();
		mq.pop();
		cur = cur->next;
		// ÿ�������������Ԫ��ʱһ��Ҫ��֤��������
		if (cur->next)
			mq.push(cur->next);
	}
	return start.next;
}