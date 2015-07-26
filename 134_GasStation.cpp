#include "mainheader.h"
/*
	�ҵķ������Ӷȹ��ߣ��ظ������˺ܶ಻��Ҫ�������ֵ��
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
	���ʣ�
		1.��� A �� B ʣ��gas�������㣬��ô����A��B֮��ĵ㶼���ܵ���B��
		2.���еĺ�С�����򲻴��������ĵ㣬�����������һ�����������ĵ㡣
	��������
*/
int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
	int T = gas.size();
	int total(0), tank(0),start(0);
	for (int i = 0; i < T; i++){
		total += gas[i] - cost[i];
		tank += gas[i] - cost[i];
		if (tank < 0){
			// ���¿�ʼ����
			tank = 0;
			start = i + 1;
		}
	}	
	return (total >= 0) ? start: -1;
}