#include "mainheader.h"
#include <unordered_map>
#include <algorithm>

/*
	我的方法：
	1.Hash map；
	2.两个指针

	注意：原先的想法是将Map进行清空，但是复杂度太高。经过思考以后，发现不需要清空，而是只要清除一部分就行。

	现在还是在用下标实现算法，到时候可以学习使用指针即迭代器进行使用。

	*****
	方法改进：
		1.使用一个exist[256] = false 的数组来代替hash_map
		2.使用while（）代替for语句执行。
	使用exitst的数组代替hash_map的内在哲学思想是思考所考虑的元素的空间维度，因为元素只有256种状态，所以就不必要使用hash_map这样的无限维的数据结构。
	hash_map需要使用的是erase方法，而使用数组进行查找和删除都只需要使用ture与false设值。
*/

int lengthOfLongestSubstring(string s){
	unordered_map<int, int> mp;
	unsigned int T = s.size();
	int ml = 0; //最大的字串长度
	int lh = 0;
	int rh = 0;
	for (unsigned int i = 0; i < T; i++){
		//如果s[i]不存在于mp中，则将s[i]添加到mp中，并且count++
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