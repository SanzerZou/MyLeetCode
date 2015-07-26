#include "mainheader.h"
#include <algorithm>
int threeSumClosest(vector<int>& nums, int target) {
	int res = INT_MAX;
	int min = INT_MAX;
	vector<int> mnums = nums;
	sort(mnums.begin(), mnums.end());
	int T = mnums.size();

	for (int i = 0; i < T - 2; i++){
		int lh = i + 1;
		int rh = T - 1;
		int nagate = target - mnums[i];
		while (lh < rh){
			if (mnums[lh] + mnums[rh] >= nagate){
				if (mnums[lh] + mnums[rh] - nagate < min){
					min = mnums[lh] + mnums[rh] - nagate;
					res = mnums[lh] + mnums[rh] + mnums[i];
				}
				rh--;
			}
			else{
				if (nagate - mnums[lh] - mnums[rh] < min){
					min = nagate - mnums[lh] - mnums[rh];
					res = mnums[lh] + mnums[rh] + mnums[i];
				}
				lh++;
			}
		}
	}
	return res;
}