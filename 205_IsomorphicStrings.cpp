#include "mainheader.h"

bool isIsomorphic(string s, string t) {
	vector<char> mv(256, 0);
	vector<bool> mb(256, false);
	for (int i = 0; i < s.size(); i++){
		if (!mv[s[i]] && !mb[t[i]]){
			mv[s[i]] = t[i];
			mb[t[i]] = true;
		}
	
		else if (mv[s[i]] == t[i])
			continue;
		else
			return false;
	}
	return true;
}
//int main(){
//	string s = "ab";
//	string t = "ab";
//	bool res = isIsomorphic(s, t);
//	return 0;
//}