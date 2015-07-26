#include "mainheader.h"
#include <unordered_map>
#include <algorithm>

/*
	�ҵķ�����
	1.Hash map��
	2.����ָ��

	ע�⣺ԭ�ȵ��뷨�ǽ�Map������գ����Ǹ��Ӷ�̫�ߡ�����˼���Ժ󣬷��ֲ���Ҫ��գ�����ֻҪ���һ���־��С�

	���ڻ��������±�ʵ���㷨����ʱ�����ѧϰʹ��ָ�뼴����������ʹ�á�

	*****
	�����Ľ���
		1.ʹ��һ��exist[256] = false ������������hash_map
		2.ʹ��while��������for���ִ�С�
	ʹ��exitst���������hash_map��������ѧ˼����˼�������ǵ�Ԫ�صĿռ�ά�ȣ���ΪԪ��ֻ��256��״̬�����ԾͲ���Ҫʹ��hash_map����������ά�����ݽṹ��
	hash_map��Ҫʹ�õ���erase��������ʹ��������в��Һ�ɾ����ֻ��Ҫʹ��ture��false��ֵ��
*/

int lengthOfLongestSubstring(string s){
	unordered_map<int, int> mp;
	unsigned int T = s.size();
	int ml = 0; //�����ִ�����
	int lh = 0;
	int rh = 0;
	for (unsigned int i = 0; i < T; i++){
		//���s[i]��������mp�У���s[i]��ӵ�mp�У�����count++
		if (!mp.count(s[i]))
		{
			mp.insert(pair<int, int>(s[i], i));
		}
		else{
			rh = mp[s[i]];
			for (int j = lh; j <= rh; j++){
				mp.erase(s[j]);
			}
			lh = rh + 1;
			mp.insert(pair<int, int>(s[i], i));
		}
		if (ml < mp.size()){
			ml = mp.size();
		}
	}
	return ml;
}