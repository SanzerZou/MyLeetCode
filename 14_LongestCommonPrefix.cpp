#include "mainheader.h"
/*
	问题难点在于边界条件的考虑：
		1.string 为空的时候，这种情况是不会进入循环的，所以直接返回空
		2.当最短的string为空的时候也是不会进入for循环的，因为 0 < mSize,所以也要特殊考虑
		3.当循环没有return要特殊考虑，直接返回最短的字符串

*/
string longestCommonPrefix(vector<string>& strs) {
	// 特殊情况一
	if (strs.empty() == true){
		return "";
	}
	else if(strs.size() == 1){
		return strs[0];
	}
	int T = strs.size();
	int mSize = strs[0].size();
	// 找出最短字符串
	for (int i = 0; i < T; i++){
		if (mSize > strs[i].size()){
			mSize = strs[i].size();
		}
	}
	// 特殊情况二
	if (mSize == 0){
		return "";
	}
	char tp;
	// 横向与纵向两重循环，遇到不相等的情况即return
	for (int dp = 0; dp < mSize; dp++){
		tp = strs[0][dp];
		for (int j = 0; j < T; j++){
			if (tp != strs[j][dp]){
				return strs[0].substr(0, dp);
			}
		}
	}
	// 特殊情况三
	return strs[0].substr(0, mSize);
}