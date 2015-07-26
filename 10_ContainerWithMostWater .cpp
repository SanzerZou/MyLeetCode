#include "mainheader.h"
#include <vector>
// 核心思想是移动时，只有内边大于最大边时才有可能大于最大面积。

// 明天再总结
int maxArea(vector<int>& height) {
	int n = height.size();
	// 标记左边和右边的最优高度
	int lh = height[0];
	int rh = height[n - 1];
	// 标记用户计算面积的高度，即短边的高度
	int tH = (lh >= rh) ? rh : lh;
	// 标记最大面积
	int maxA = tH*(n - 1);
	// 标记左右边的最优指针地址
	int li = 0;
	int ri = n - 1;
	// 哪边小则移动哪边的指针
	bool bf = (lh < rh) ? true : false;
	int i = 0, j = n - 1;
	while (j > i){
		if (bf){
			if (height[i] > lh){
				li = i;
				lh = height[i];
				tH = (height[i] >= rh) ? rh : height[i];
				bf = (lh < rh) ? true : false;
				if (tH*(ri - i) > maxA){
					maxA = tH*(ri - i);
				}
			}
		}
		else{
			if (height[j] > rh){
				ri = j;
				rh = height[j];
				bf = (lh < rh) ? true : false;
				tH = (height[j] >= lh) ? lh : height[j];
				if (tH*(j - li) > maxA){
					maxA = tH*(j - li);
				}
			}
		}
		//更新左右指针值
		if (bf) i++;
		else j--;
	}
	return maxA;
}