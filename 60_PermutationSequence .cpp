#include "mainheader.h"
#include <algorithm>
/*
	��һ�ֽⷨ��dfs backtracking����ֱ���鵽��k����Ϊֹ�����ַ���������Ϊ��ϰbacktracking�ķ���������
	���ӶȽϸߣ���Ҫ�����k����֮ǰ��������ϣ�����Щ���ǲ���Ҫ��
*/

//void dfs(vector<bool> flg,vector<int>& nums,
//	int index,int &count,bool &bk,const int n,const int k){
//	if (index == n){
//		count++;
//		if (count == k){
//			bk = true;
//			return;
//		}
//	}
//	else{
//		for (int i = 0; i < n; i++){
//			if (flg[i] == false){
//				flg[i] = true;
//				nums[index] = i + 1;
//				dfs(flg, nums, index + 1, count, bk, n, k);
//				if (bk) return;
//				flg[i] = false;
//			}
//		}
//	}
//}
/*
	����������������Ϊ���ƣ�ĳһλ�����ж�����������ϣ���ǰһλ�Ƕ��١�
*/
int factorial(int n, vector<int> &mv,int index){
	if (n == 0){
		return 1;
	}
	else{
		return mv[index] = n*factorial(n - 1, mv, index + 1);
	}
}
string getPermutation(int n, int k) {
	vector<char> tp(n,0); //��ŵ�ǰ�ŵڼ����ַ����ǵ�ÿ��ѭ��ɾ��һ��
	vector<char> nums(n, 0); //�����������vector
	vector<int> fac(n - 1, 0); //��Ž׳˳���
	string res;
	// �ַ�����ʼ������1��~��9��
	for (int i = 0; i < n; i++){
		tp[i] = (char)(i + '1');
	}
	// ��׳���
	factorial(n - 1, fac, 0);
	k--; // ע���ȥһ����Ϊ�������Ǵ��㿪ʼ��
	// ÿ�����һλ
	for (int i = 0; i < n - 1; i++){
		int index = k / fac[i];
		nums[i] = tp[index];
		tp.erase(tp.begin() + index);
		k -= index * fac[i];
	}
	nums[n - 1] = tp[0];
	for (int i = 0; i < n; i++){
		res += nums[i];
	}
	return res;
}

//int main(){
//	string res = getPermutation(1, 1);
//	return 0;
//}