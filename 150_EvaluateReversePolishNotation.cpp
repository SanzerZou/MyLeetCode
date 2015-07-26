#include "mainheader.h"
#include <stack>
int myconvert(string in, int& res){
	res = 0;
	switch (in[0]){
	case '+':
		return 1;
		break;
	case '-':
		if (in.size() == 1)
			return 2;
		else{
			for (int i = 1; i < in.size(); i++){
				res = res * 10 + (in[i] - '0');
			}
			res = -res;
			return 0;
		}
		break;
	case '*':
		return 3;
		break;
	case '/':
		return 4;
		break;
	default:
		for (int i = 0; i < in.size(); i++){
			res = res * 10 + (in[i] - '0');
		}
		return 0;
		break;
	}
}
int evalRPN(vector<string>& tokens) {
	stack<int> ms;
	for (int i = 0; i < tokens.size(); i++){
		int tp = 0;
		int flg = myconvert(tokens[i], tp);
		int a, b;
		if (flg != 0){
			a = ms.top();
			ms.pop();
			b = ms.top();
			ms.pop();
		}
		switch (myconvert(tokens[i], tp))
		{
			case 0:
				ms.push(tp);
				break;
			case 1:
				ms.push(b + a);
				break;
			case 2:
				ms.push(b - a);
				break;
			case 3:
				ms.push(b * a);
				break;
			case 4:
				ms.push(b / a);
				break;
			default:
				break;
		}
	}
	return ms.top();
}
//int  main(){
//	vector<string> s = { "4", "13", "5", "/", "+" };
//	int res = evalRPN(s);
//	return 0;
//}