#include "mainheader.h"
#include <unordered_map>
/*
	�ҵ�˼����
		1.ʹ������Ȼ�������������Ӷ�Ϊ O(Nlog(N));
		2.��Ϊ�ǲ��ң�����ʹ��unordered_map��������ı�һ��״̬��ʹ��iterator��������it->first:��ʾ��һ��Ԫ�أ�it->second:��ʾ�ڶ���Ԫ��
		3.unordered_map��iterator����ʹ�á�<�� , ��ֻ��ʹ�� ��!=��
	��֮���ҵķ������㸴�Ӷ��е�ߡ�
*/
int singleNumber(vector<int>& nums) {
	int T = nums.size();
	unordered_map<int,bool> mp;
	for (int i = 0; i < T; i++){
		if (mp.count(nums[i])){
			mp.insert({ nums[i], false });
		}
		else{
			mp[nums[i]] = !mp[nums[i]];
		}
	}
	unordered_map<int, bool>::iterator it = mp.begin();
	for (; it != mp.end(); it++){
		if (!(it->second))
			return it->first;
	}
}
/*
	�������������
		ʹ��XOR������ԭ��((2^2)^(1^1)^(4^4)^(5)) => (0^0^0^5) => 5
		���� XOR ���� = 0��
		0 XOR ���� = ����
		FF XOR ���� = ������
*/
int singleNumber2(int A[], int n) {
	int result = 0;
	for (int i = 0; i<n; i++)
	{
		result ^= A[i];
	}
	return result;
}

//int main(){
//	vector<int> inv(1, 1);
//	int res = singleNumber(inv);
//	return 0;
//}