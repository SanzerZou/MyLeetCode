#include "mainheader.h"

int lengthOfLastWord(string s) {
	int T = s.size();
	if (T == 0)
		return 0;
	int count = 0;
	int i = T - 1;
	while (s[i] == ' ')
		i--;
	for (; i >= 0; i--){
		if (s[i] != ' ')
			count++;
		else
			break;
	}
	return count;
}