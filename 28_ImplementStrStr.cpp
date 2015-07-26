#include "mainheader.h"
/*
	��Ŀ�ܼ򵥴�����ֵĵط���
		1.��ѭ��Ƕ��ʱ��Ҫ��֤����ѭ����ֵ���ᳬ������ѭ��������
		2.һ��Ҫע�⣬��if()�е��жϺ��� ��==�� ������ ��=��
	ţ���㷨���ַ���ƥ��
		1.KMP������needle�Ĺ��ɣ����Ƿ����ڲ���ƥ���ϵ�����ò�ƥ��ʱ����Ϣʹ�ƶ�������С��
		2.Boyer-Moore
		3.���Ϸ���������needle�ַ����Ƚϳ�ʱ������
*/
int strStr(string haystack, string needle) {
	int T1 = haystack.size();
	int T2 = needle.size();
	int res = -1;
	// �߽�����
	if (needle.empty()){
		return 0;
	}
	else if (haystack.empty()){
		return -1;
	}
	// ѭ������
	for (int i = 0; i < T1 - T2 + 1; i++){
		if (haystack[i] == needle[0]){
			int j;
			for (j = 0; j < T2; j++){
				if (haystack[i + j] == needle[j])
					continue;
				else
				{
					break;
				}
			}
			if (j == T2){
				res = i;
				return res;
			}
		}
	}
	return res;

}