#include "mainheader.h"

string countAndSay(int n) {
	string tp;
	string res = "1";
	char tpc;
	int count = 0;
	while (--n){
		tp = res;
		res.clear();
		int T = tp.size();
		for (int i = 0; i < T;){
			char tpc = tp[i];
			int count = 0;
			while (tpc == tp[i]){
				i++;
				count++;
			}
			res += (char)(count + '0');
			res += tpc;
		}
	}
	return res;
}