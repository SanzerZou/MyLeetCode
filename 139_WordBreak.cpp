#include "mainheader.h"
#include <unordered_set>
/*
	动态规划，因为当前位置的状态与前面之前的很多状态都有关系，复杂度为 O(n^2);
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
				// 第一个参数表示开始位置，第二个参数表示词长度。注意，起始位置为j后边以为，又因为数组
				// 坐标多减一，所以结果为j。 长度为边界值减去起始位置。
				string word = s.substr(j, i - j);
				// 查找 word 是否在set中，如果不在则为队尾
				if (wordDict.find(word) != wordDict.end()){
					dp[i] = true;
					// 只有一个满足条件则跳出循环，每个位置只有1 bit的信息，true or false；
					break;
				}
			}
		}
	}
	return dp[s.size()];
}