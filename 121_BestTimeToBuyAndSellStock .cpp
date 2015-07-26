#include "mainheader.h"

int maxProfit(vector<int>& prices) {
	int mx = 0;
	int mi = INT_MAX;
	int T = prices.size();
	if (T < 2){
		return 0;
	}
	for (int i = 0; i < T; i++){
		if (prices[i] < mi){
			mi = prices[i];
		}
		else{
			if (prices[i] - mi > mx){
				mx = prices[i] - mi;
			}
		}
	}
	return mx;
}