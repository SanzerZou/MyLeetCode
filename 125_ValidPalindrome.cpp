#include "mainheader.h"
#include <cctype>

bool isPalindrome(string s) {
	if (s.empty()){
		return true;
	}
	string so;
	// ���ַ���ת��ΪСд���Է��ַ�
	string::iterator it = s.begin();
	for (; it < s.end(); it++){
		if(isalnum(*it)){
			// ����Ǵ�д��ת��ΪСд���������ֱ�Ӽ����ַ�����
			so += (isupper(*it))?(tolower(*it)):*it;
		}
	}
	int T = so.size();
	if (T < 2){
		return true;
	}
	else{
		// Ϊż��
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