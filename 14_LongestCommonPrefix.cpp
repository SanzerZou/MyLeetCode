#include "mainheader.h"
/*
	�����ѵ����ڱ߽������Ŀ��ǣ�
		1.string Ϊ�յ�ʱ����������ǲ������ѭ���ģ�����ֱ�ӷ��ؿ�
		2.����̵�stringΪ�յ�ʱ��Ҳ�ǲ������forѭ���ģ���Ϊ 0 < mSize,����ҲҪ���⿼��
		3.��ѭ��û��returnҪ���⿼�ǣ�ֱ�ӷ�����̵��ַ���

*/
string longestCommonPrefix(vector<string>& strs) {
	// �������һ
	if (strs.empty() == true){
		return "";
	}
	else if(strs.size() == 1){
		return strs[0];
	}
	int T = strs.size();
	int mSize = strs[0].size();
	// �ҳ�����ַ���
	for (int i = 0; i < T; i++){
		if (mSize > strs[i].size()){
			mSize = strs[i].size();
		}
	}
	// ���������
	if (mSize == 0){
		return "";
	}
	char tp;
	// ��������������ѭ������������ȵ������return
	for (int dp = 0; dp < mSize; dp++){
		tp = strs[0][dp];
		for (int j = 0; j < T; j++){
			if (tp != strs[j][dp]){
				return strs[0].substr(0, dp);
			}
		}
	}
	// ���������
	return strs[0].substr(0, mSize);
}