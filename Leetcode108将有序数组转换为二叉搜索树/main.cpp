//
// Created by 橙子味 on 2025/1/14.
//
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void GenerateBST(TreeNode* cur, vector<int>& nums, int left, int right){
    int middle = (right+left)/2;
    cur->val = nums[middle];
    if (left >= right) return;
    if (middle>left){
        cur->left = new TreeNode();
        GenerateBST(cur->left, nums, left, middle-1);
    }
    if (middle<right){
        cur->right = new TreeNode();
        GenerateBST(cur->right, nums, middle+1, right);
    }
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root;
    if (nums.size() > 0)
        root = new TreeNode();
    else
        root = nullptr;
    GenerateBST(root, nums, 0, nums.size()-1);
    return root;
}
int main()
{
  vector<int> nums1 = {1,2,3,4,5,6,7,8,9,10};
    sortedArrayToBST(nums1);
}