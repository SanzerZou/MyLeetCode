#include "mainheader.h"
#include <algorithm>
int minimumTotal(vector<vector<int> > &triangle) {
	int T = triangle.size();
	if (T == 0)
		return 0;
	if (T == 1)
		return triangle[0][0];
	else if (T == 2)
		return triangle[0][0] + min(triangle[1][0], triangle[1][1]);
	for (int i = 1; i < T; i++){
		for (int j = 0; j < triangle[i].size(); j++){
			if (j != 0 && j != triangle[i].size() - 1)
				triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
			else if (j == 0){
				triangle[i][0] += triangle[i - 1][0];
			}
			else if (j == triangle[i].size() - 1)
				triangle[i][j] += triangle[i - 1][j - 1];
		}
	}
	return *min_element(triangle[T - 1].begin(),triangle[T - 1].end());
}