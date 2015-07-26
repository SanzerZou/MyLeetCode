#include "mainheader.h"
/*
	dfs:������Ⱦ����㷨�����ݷ�����һ�����á��㷨����һ��һ�ε��Ż���
	�ҵ��㷨��
		���û��ݷ�������п��ܣ�Ȼ�����ж�ÿһ�ֿ����Ƿ�������Ҫ������Ŷ�
	�Ż��㷨:
		�ҳ����ŶԵĹ��ɣ�������Ҫ�������п��ܣ���������ַ�������������������Ŷԣ�û�е��жϵĹ��̡�
	���ݷ���
		�ǵö�ʹ�ü���������Ȼ��ʹ�á�&�������д��ݡ��β�Ҳ�ǿ��Ա�ã�ѧ��ʹ�����������
*/
void dfsGen(vector<string> &res,string out, int lh, int rh, int sum){
	if (!lh){
		string temp(rh, ')');
		res.push_back(out + temp);
		return;
	}
	dfsGen(res, out + '(', lh - 1, rh, sum + 1);
	if (sum > 0)
		dfsGen(res, out + ')', lh, rh - 1, sum - 1);
}
vector<string> generateParenthesis(int n) {
	vector<string> res;
	dfsGen(res,"", n, n, 0);
	return res;
}
/*
	���Դ��룺
*/
//int main(){
//	vector<string> tp = generateParenthesis(3);
//	return 0;
//}