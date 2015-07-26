#include "mainheader.h"

string convertToTitle(int n) {
	string res;
	while (n){
		int tp = n % 26;
		if (tp){
			res += char('A' + tp - 1);
			n /= 26;
		}
		else{
			res += 'Z';
			n = n / 26 - 1;
		}
	}
	reverse(res.begin(), res.end());
	return res;
}