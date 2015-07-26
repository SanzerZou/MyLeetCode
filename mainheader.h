#include <iostream>
#include <vector>
#include <string>

using namespace std;
//两个数相加等于定值
vector<int> twoSum(vector<int>& nums, int target);
// 求最长子字符串
int lengthOfLongestSubstring(string s);
// 找出第k小的数字
int findKthSmallest(int A[], int m, int B[], int n, int k);
// z字型字符串转换
string convert(string s, int numRows);
// 反相输出int
int reverse(int x);
// 看int是否为回文数
bool isPalindrome(int x);
// 求解两个line之间最大的Area
int maxArea(vector<int>& height);
// 将int整数转化为roman数字
string intToRoman(int num);
// 将roman数字转化为int整数
int romanToInt(string s);
// 最长共同前缀
string longestCommonPrefix(vector<string>& strs);
// 三个数相加等于零
vector<vector<int>> threeSum(vector<int>& nums);

vector<vector<int>> fourSum(vector<int>& nums, int target);

bool isPalindrome(string s);

bool isValid(string s);

int removeDuplicates(vector<int>& nums);

int removeElement(vector<int>& nums, int val);

int strStr(string haystack, string needle);

void nextPermutation(vector<int>& nums);

int search(vector<int>& nums, int target);

vector<int> searchRange(vector<int>& nums, int target);

int searchInsert(vector<int>& nums, int target);

string countAndSay(int n);

vector<vector<int>> combinationSum(vector<int>& candidates, int target);

vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

int trap(vector<int>& height);

vector<vector<int>> permute(vector<int>& nums);

double myPow(double x, int n);

int climbStairs(int n);

int rob(vector<int>& nums);

int numTrees(int n);

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

vector<int> spiralOrder(vector<vector<int>>& matrix);

int lengthOfLastWord(string s);

vector<vector<int>> generateMatrix(int n);

string getPermutation(int n, int k);

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
};