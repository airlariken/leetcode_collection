//
// Created by 橙子味 on 2025/1/16.
// leetcode 直接写的
#include <climits>
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
class Solution {
public:
    bool visit(TreeNode* cur, long long int lower,long long  int upper){
        if (cur == nullptr)return true;
        if (lower < cur->val && cur->val < upper)
            return visit(cur->left, lower, cur->val) && visit(cur->right, cur->val, upper);
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {
        return visit(root, LONG_MIN, LONG_MAX);
    }
};

int main() {
  Solution s;
  TreeNode root;
}