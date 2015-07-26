#include "mainheader.h"

string extentCenter(const string &s, int lh, int rh)
{
	int c1 = lh;
	int c2 = rh;
	int n = s.length();
	while (c1 >= 0 && c2 < n && s[c1] == s[c2]){
		c1--;
		c2++;
	}
	return s.substr(c1 + 1, c2 - c1 - 1);	 //加一减一的原因是判断相等以后多加一减一
}

int longestPalindrome(const string &s)
{
	int n = s.length();
	int maxLength = 0;
	string tempS;
	string maxString;
	for (unsigned int i = 0; i < n; i++)
	{
		tempS = extentCenter(s, i, i);
		if (tempS.length() > maxLength){

			maxString = tempS;
			maxLength = tempS.length();
		}
		tempS = extentCenter(s, i, i + 1);
		if (tempS.length() > maxLength){
			maxString = tempS;
			maxLength = tempS.length();
		}
	}
	return maxLength;
}