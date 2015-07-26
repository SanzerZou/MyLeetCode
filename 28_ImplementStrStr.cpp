#include "mainheader.h"
/*
	题目很简单错误出现的地方：
		1.当循环嵌套时，要保证里重循环的值不会超出外重循环的限制
		2.一定要注意，在if()中的判断号是 ‘==’ 而不是 ‘=’
	牛逼算法：字符串匹配
		1.KMP：分析needle的规律，看是否有内部的匹配关系，利用不匹配时的信息使移动次数最小。
		2.Boyer-Moore
		3.以上方法都是在needle字符串比较长时有优势
*/
int strStr(string haystack, string needle) {
	int T1 = haystack.size();
	int T2 = needle.size();
	int res = -1;
	// 边界条件
	if (needle.empty()){
		return 0;
	}
	else if (haystack.empty()){
		return -1;
	}
	// 循环查找
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