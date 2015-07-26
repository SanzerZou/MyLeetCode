#include "mainheader.h"
#include <climits>
/*
	题目：给定两个排好序的数组，数组大小为m和n，找出中间数值。如果（m+n）为偶数，则表示中间数值不存在，
		则中间数值表示中间两个数值的(Aj + Bj)/2。

	问题一般化：找出两个数组中第K大的数值。

	方法：
		1.将两个数组merge，然后找下标为 k-1 的数即可。复杂度为O(m+n)。
		2.使用两个指针，如快排的二分法一样，将指针在两个数组上游走，只取前K个值，并不判断后面的数值。复杂度为O(k)
		3.最优的方法。达到O(log(M)+log(N))，要达到这样的复杂度，必须每次将解空间缩小一半。经典如二分法。
*/
int findKthSmallest(int A[], int m, int B[], int n, int k){
	//利用这种方法确定i,j只是众多方法中的一个，也可以使用其他方法，只要满足 i+j = k - 1即可
	int i = (int)((double)m / (m + n) * (k-1));
	int j = k - 1 - i;
	//这个边界条件非常重要，防止出现 i-1和i=m时没有值，而且使用三目运算符是非常明智的想法
	int Ai_1 = (i == 0) ? INT_MIN : A[i - 1];
	int Bj_1 = (j == 0) ? INT_MIN : B[j - 1];
	int Ai = (i == m) ? INT_MAX : A[i];
	int Bj = (j == n) ? INT_MAX : B[j];
	//这是跳出循环的条件，只要满足这个条件递归才会结束
	if (A[i] > Bj_1 && A[i] < Bj){
		return A[i];
	}
	else if (B[j] > Ai_1 && B[j] < A[i]){
		return B[j];
	}

	if (Ai > Bj)
	{
		// 最后的 k - j - 1非常重要，因为已经去掉了j+1个不可能的值了，所以是求第k - j - 1大的数了
		return findKthSmallest(A, i, B + j + 1, n - j - 1, k - j - 1);
	}
	else{
		return findKthSmallest(A + i + 1, m - i - 1, B ,j, k - i - 1);
	}
}

/*
	测试代码
*/
/******************************
int main(){
int A[12] = { 1, 5, 6, 10, 12, 13, 15, 17, 18, 22 ,44,46};
int B[5] = { 2, 9, 11, 16, 19 };
int res = findKthSmallest(A, 12, B, 5, 8);
return 0;
}
********************************/