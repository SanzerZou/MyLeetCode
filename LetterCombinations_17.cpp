#include "mainheader.h"
#include <map>
/*
	��ĿҪ����پŹ�����������������ĸ���
	�㷨���ࣺbacktracking ���ݷ�
	�㷨ʹ�ó�������ٶ�ά������������ϣ�ע������ٷ������õķ����ǵݹ飬���������ά�ȡ�
*/
map<char, string> mp;
const char nums[8] = { '2', '3', '4', '5', '6', '7', '8', '9' };
const string ms[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
vector<string> res;
string ins;
int size = 0;

void backTrackingLetter(string outs,int div){
	int T = mp[ins[div]].size();
	string tp = mp[ins[div]];
	// �߽�����
	if (div == size - 1){
		for (int i = 0; i < T; i++){
			outs[div]= tp[i];
			res.push_back(outs);
		}
	}
	else{
		for (int i = 0; i < T; i++){
			outs[div] = tp[i];
			backTrackingLetter(outs,div + 1);
		}
	}
}

vector<string> letterCombinations(string digits) {
	// ��ʼ��mp
	for (int i = 0; i < 8; i++){
		mp[nums[i]] = ms[i];
	}
	size = digits.size();
	ins = digits;
	backTrackingLetter(digits,0);
	return res;
}