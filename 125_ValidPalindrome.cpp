#include "mainheader.h"
#include <cctype>

bool isPalindrome(string s) {
	if (s.empty()){
		return true;
	}
	string so;
	// 将字符串转化为小写忽略非字符
	string::iterator it = s.begin();
	for (; it < s.end(); it++){
		if(isalnum(*it)){
			// 如果是大写则转化为小写，其他情况直接加上字符即可
			so += (isupper(*it))?(tolower(*it)):*it;
		}
	}
	int T = so.size();
	if (T < 2){
		return true;
	}
	else{
		// 为偶数
		int i, j;
		if (T % 2 == 0){
			i = T / 2;
			j = T / 2 - 1;
		}
		else{
			i = T / 2 + 1;
			j = T / 2 - 1;
		}
		while (i < T)
		{
			if (so[i] == so[j]){
				i++;
				j--;
			}
			else{
				return false;
			}
		} 
		return true;
	}
}