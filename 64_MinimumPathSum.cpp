#include "mainheader.h"
#include <algorithm>

int minPathSum(vector<vector<int>>& grid) {
	int H = grid.size();
	if (grid.empty())
		return 0;
	int L = grid[0].size();
	int res = 0;
	if (H == 1){
		for (int i = 1; i < L; i++){
			grid[0][i] += grid[0][i - 1];
		}
		return grid[0][L - 1];
	}
	else if(L == 1){
		for (int i = 1; i < H; i++){
			grid[i][0] += grid[i - 1][0];
		}
		return grid[H - 1][0];
	}
	else{
		for (int i = 0; i < H; i++){
			for (int j = 0; j < L; j++){
				if (i == 0 && j != 0)
					grid[0][j] += grid[0][j - 1];
				else if (j == 0 && i != 0)
					grid[i][0] += grid[i - 1][0];
				else if (i == 0 && j == 0)
					continue;
				else
					grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
			}
		}
		return grid[H - 1][L - 1];
	}
}