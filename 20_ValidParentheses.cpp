#include "mainheader.h"
#include <stack>
#include <map>

bool isValid(string s) {
	if (s.empty()){
		return true;
	}
	if (s.size() % 2 != 0){
		return false;
	}
	stack<char> ms;
	string::iterator it = s.begin();
	map<char, char> mp;
	mp['('] = ')';
	mp['{'] = '}';
	mp['['] = ']';
	for (; it < s.end(); it++){
		// ��ջΪ��ʱ�����Ԫ��
		if (ms.empty()){
			ms.push(*it);
		}
		else{
			// ʹ��map���ַ���������
			if (*it == mp[ms.top()]){
				ms.pop();
			}
			else{
				ms.push(*it);
			}
		}
	}
	if (ms.empty()){
		return true;
	}
	else{
		return false;
	}
}