//
//  main.cpp
//  Leetcode199二叉树的右视图
//
//  Created by 陈梓玮 on 2025/1/21.
// 双队列实现简单的区分层级，通过只插入非空指针，判断当前层最后一个元素为可视元素

#include <iostream>
#include <queue>
#include <vector>

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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)return vector<int>();
        vector<int> res;
        queue<TreeNode*> s1, s2;
        s1.push(root);
        while (!s1.empty() || !s2.empty()){
            while (!s1.empty()){
                auto cur = s1.front(); s1.pop();
                if (s1.empty()) res.emplace_back(cur->val);
                if (cur->left != nullptr)   s2.push(cur->left);
                if (cur->right != nullptr)  s2.push(cur->right);
            }
            swap(s1, s2);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
