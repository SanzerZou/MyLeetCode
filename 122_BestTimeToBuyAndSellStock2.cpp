#include "mainheader.h"

int maxProfit(vector<int>& prices) {
	if (prices.size() < 2)
		return 0;
	int T = prices.size();
	int res = 0;
	for (int i = 1; i < T; i++){
		if (prices[i] - prices[i - 1] > 0){
			res += prices[i] - prices[i - 1];
		}
	}
	return res;
}