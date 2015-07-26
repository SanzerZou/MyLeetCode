#include "mainheader.h"
double absPow(double x, int n){
	if (n == 1)
		return x;
	if (n % 2 == 0){
		double res = absPow(x, n / 2);
		return res*res;
	}
	else{
		double res = absPow(x, n / 2);
		return res*res*x;
	}
}
double myPow(double x, int n) {
	// ע��������� -1��1��
	if (abs(x) == 1.0){
		return (n % 2)?x:abs(x);
	}
	if (n == 0){
		return 1.0;
	}
	else if (n > 0){
		return absPow(x, n);
	}
	else{
		return 1.0 / absPow(x, -n);
	}
}

/*
�����ŵĽⷨ��
double pow(double x, int n) {
	if(n == 0)
		return 1;
	if(n<0){
		n = -n;
		x = 1/x;
	}
		return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
}
*/