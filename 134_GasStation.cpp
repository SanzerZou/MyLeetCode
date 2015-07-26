#include "mainheader.h"
/*
	我的方法复杂度过高，重复计算了很多不需要计算的数值。
*/
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int T = gas.size();
	for (int i = 0; i < T; i++){
		int remain = 0;
		int j = 0;
		for (int k = i; j < T; k = (k + 1)% T,j++){
			if (gas[k] + remain >= cost[k])
				remain = gas[k] + remain - cost[k];
			else
				break;
		}
		if (j == T && remain >= 0){
			return i;
		}
	}
	return -1;
}
/*
	性质：
		1.如果 A 到 B 剩余gas不大于零，那么所有A到B之间的点都不能到达B。
		2.所有的和小于零则不存在这样的点，如果大于零则一定存在这样的点。
	方法二：
*/
int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
	int T = gas.size();
	int total(0), tank(0),start(0);
	for (int i = 0; i < T; i++){
		total += gas[i] - cost[i];
		tank += gas[i] - cost[i];
		if (tank < 0){
			// 重新开始计数
			tank = 0;
			start = i + 1;
		}
	}	
	return (total >= 0) ? start: -1;
}