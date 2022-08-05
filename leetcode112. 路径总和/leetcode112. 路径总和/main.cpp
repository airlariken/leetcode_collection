//
//  main.cpp
//  leetcode112. 路径总和
//
//  Created by 陈梓玮 on 2022/7/31.
//https://leetcode.cn/problems/path-sum/
//核心思想DFS，全局变量维护partial sum

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int partial_sum = 0;
    bool traverse(TreeNode* cur, int targetSum){
        if(cur == nullptr)
            return false;
        partial_sum+=cur->val;
        if(cur->left ==nullptr && cur->right == nullptr && partial_sum == targetSum)
            return true;
        bool flag  =traverse(cur->left, targetSum) || traverse(cur->right, targetSum);
        partial_sum-=cur->val;
        return flag;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return traverse(root, targetSum);
    }

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    hasPathSum(root, 100);
    std::cout << "Hello, World!\n";
    return 0;
}
