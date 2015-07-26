#include "mainheader.h"
#include <map>
/*
	题目要求：穷举九宫格数字码表的所有字母组合
	算法归类：backtracking 回溯法
	算法使用场景：穷举多维向量的所有组合，注意是穷举法。常用的方法是递归，输入参数是维度。
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
	// 边界条件
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
	// 初始化mp
	for (int i = 0; i < 8; i++){
		mp[nums[i]] = ms[i];
	}
	size = digits.size();
	ins = digits;
	backTrackingLetter(digits,0);
	return res;
}