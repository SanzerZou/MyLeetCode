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
	// 首先创建表头
	ListNode start(0);
	ListNode* cur = &start;
	// 创建优先队列
	priority_queue<ListNode*, vector<ListNode*>, CompareNode> mq;
	// 为优先队列添加元素
	for (vector<ListNode*>::iterator it = lists.begin(); it < lists.end(); ++it){
		if (*it){
			mq.push(*it);
		}
	}
	// 处理元素
	while (!mq.empty()){
		cur->next = mq.top();
		mq.pop();
		cur = cur->next;
		// 每次往容器中添加元素时一定要保证满足条件
		if (cur->next)
			mq.push(cur->next);
	}
	return start.next;
}