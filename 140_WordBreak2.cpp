#include "mainheader.h"
#include <unordered_set>

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
	vector<bool> dp(s.size() + 1, false);
	vector<vector<string>> mv(s.size() + 1, vector<string>());
	dp[0] = true;
	mv[0].push_back("");
	for (int i = 1; i <= s.size(); i++){
		for (int j = i - 1; j >= 0; j--){
			if (dp[j]){
				string word = s.substr(j, i - j);
				if (wordDict.find(word) != wordDict.end()){
					dp[i] = true;
					for (int k = 0; k < mv[j].size(); k++){
						if (j == 0)
							mv[i].push_back(word);
						else
							mv[i].push_back(mv[j][k] + " " + word);
					}
				}
			}
		}
	}
	return mv[s.size()];
}
//int main(){
//	unordered_set<string> wordDict = { "a", "aa", "aaa", "aaaa", "aab", "b" };
//	string s = "aaaaaaaaab";
//	vector<string> res = wordBreak(s, wordDict);
//	return 0;
//
//}