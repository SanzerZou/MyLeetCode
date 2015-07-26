#include <iostream>
#include <vector>
#include <string>

using namespace std;
//��������ӵ��ڶ�ֵ
vector<int> twoSum(vector<int>& nums, int target);
// ������ַ���
int lengthOfLongestSubstring(string s);
// �ҳ���kС������
int findKthSmallest(int A[], int m, int B[], int n, int k);
// z�����ַ���ת��
string convert(string s, int numRows);
// �������int
int reverse(int x);
// ��int�Ƿ�Ϊ������
bool isPalindrome(int x);
// �������line֮������Area
int maxArea(vector<int>& height);
// ��int����ת��Ϊroman����
string intToRoman(int num);
// ��roman����ת��Ϊint����
int romanToInt(string s);
// ���ͬǰ׺
string longestCommonPrefix(vector<string>& strs);
// ��������ӵ�����
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