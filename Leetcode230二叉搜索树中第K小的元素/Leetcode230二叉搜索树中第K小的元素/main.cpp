//
//  main.c
//  Leetcode230二叉搜索树中第K小的元素
//
//  Created by 陈梓玮 on 2025/1/21.
//

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
    TreeNode* visit(TreeNode* cur, int *cur_k, int k){
        if (cur == nullptr) return nullptr;
        auto p = visit(cur->left, cur_k, k);
        *cur_k += 1;
        if (*cur_k == k) return cur;
        if (p != nullptr)   return p;
        p = visit(cur->right, cur_k, k);
        return p;
    }
    int kthSmallest(TreeNode* root, int k) {
        int* cur_k = new int(0);
        auto res_p = visit(root, cur_k, k);
        if (res_p != nullptr)   return res_p->val;
        else return -123;
    }
};

int main()
{
    return 0;
}
