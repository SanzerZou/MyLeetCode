#include "mainheader.h"

void reverseWords(string &s) {
	string res;
	for (int i = s.size() - 1; i >= 0;){
		string tp;
		while (i >= 0 && s[i] == ' ')
			i--;
		while (i >= 0 && s[i] != ' ')
			tp += s[i--];
		if (!tp.empty()){
			reverse(tp.begin(), tp.end());
			res += tp + ' ';
		}
	}
	if (!res.empty())
		res.pop_back();
	s = res;
}
//int main(){
//	string s = "  the sky is blue  ";
//	reverseWords(s);
//	return 0;
//}