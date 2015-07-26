#include "mainheader.h"
#include <unordered_set>
/*
	��̬�滮����Ϊ��ǰλ�õ�״̬��ǰ��֮ǰ�ĺܶ�״̬���й�ϵ�����Ӷ�Ϊ O(n^2);
*/
bool wordBreak(string s, unordered_set<string>& wordDict) {
	vector<bool> dp(s.size() + 1, false);
	unordered_set<string>::iterator it = wordDict.begin();
	int T = 0;
	while (it != wordDict.end()){
		if ((*it).size() > T)
			T = (*it).size();
		it++;
	}
	dp[0] = true;
	for (int i = 1; i <= s.size(); i++){
		for (int j = i - 1; j >= i - T && j >= 0; j--){
			if (dp[j]){
				// ��һ��������ʾ��ʼλ�ã��ڶ���������ʾ�ʳ��ȡ�ע�⣬��ʼλ��Ϊj�����Ϊ������Ϊ����
				// ������һ�����Խ��Ϊj�� ����Ϊ�߽�ֵ��ȥ��ʼλ�á�
				string word = s.substr(j, i - j);
				// ���� word �Ƿ���set�У����������Ϊ��β
				if (wordDict.find(word) != wordDict.end()){
					dp[i] = true;
					// ֻ��һ����������������ѭ����ÿ��λ��ֻ��1 bit����Ϣ��true or false��
					break;
				}
			}
		}
	}
	return dp[s.size()];
}