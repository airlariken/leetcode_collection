//
//  main.cpp
//  leetcode144 二叉树的前序遍历(非递归)
//
//  Created by 陈梓玮 on 2022/7/24.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//  //递归
// class Solution {
// public:
//     void traverse(TreeNode *node, vector<int>& res){
//         if(node == nullptr)
//             return;
//         res.push_back(node->val);
//         traverse(node->left, res);
//         traverse(node->right, res);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         traverse(root, res);
//         return res;
//     }
// };
 //非递归
class Solution {
public:
    stack<TreeNode*> s;
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr)
            return vector<int>();
        s.push(root);
        while (!s.empty()) {
            TreeNode* cur = s.top();    s.pop();
            res.push_back(cur->val);
            if(cur->right != nullptr)
                s.push(cur->right);
            if(cur->left != nullptr)
                s.push(cur->left);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
