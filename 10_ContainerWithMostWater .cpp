#include "mainheader.h"
#include <vector>
// ����˼�����ƶ�ʱ��ֻ���ڱߴ�������ʱ���п��ܴ�����������

// �������ܽ�
int maxArea(vector<int>& height) {
	int n = height.size();
	// �����ߺ��ұߵ����Ÿ߶�
	int lh = height[0];
	int rh = height[n - 1];
	// ����û���������ĸ߶ȣ����̱ߵĸ߶�
	int tH = (lh >= rh) ? rh : lh;
	// ���������
	int maxA = tH*(n - 1);
	// ������ұߵ�����ָ���ַ
	int li = 0;
	int ri = n - 1;
	// �ı�С���ƶ��ıߵ�ָ��
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
		//��������ָ��ֵ
		if (bf) i++;
		else j--;
	}
	return maxA;
}