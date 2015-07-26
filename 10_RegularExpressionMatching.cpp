#include "mainheader.h"
/**
* f[i][j]: if s[0..i-1] matches p[0..j-1]
* if p[j - 1] != '*'
*      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
* if p[j - 1] == '*', denote p[j - 2] with x
*      f[i][j] is true iff any of the following is true
*      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
*      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
* '.' matches any single character
*/
bool isMatch(string s, string p) {
	if (p.empty())
		return s.empty();
	int m = s.size();
	int n = p.size();
	vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
	f[0][0] = true;
	for (int i = 1; i <= n; i++){
		// p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
		f[0][i] = i > 1 && f[0][i - 2] && (p[i - 1] == '*');
	}
	for (int i = 1; i <= m; i++){
		f[i][0] = false;
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (p[j - 1] != '*'){
				f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
			else{
				// p[0] cannot be '*' so no need to check "j > 1" here
				f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && f[i - 1][j];
			}
		}
	}
	return f[m][n];
}
//int main(){
//	string s = "aab";
//	string t = "c*.*b";
//	bool res = isMatch(s, t);
//	return 0;
//}