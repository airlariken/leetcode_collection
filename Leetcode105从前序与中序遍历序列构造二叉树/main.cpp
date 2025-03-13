//
// Created by 橙子味 on 2025/2/17.
// 难度不小我去，debug半天
#include <algorithm>
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
void build(TreeNode* cur, int ll, int lr, int rl, int rr, vector<int>::iterator& preord_it, vector<int>&inorder){
    //visit left subtree
    if (ll <= lr) {
        int left_sub_tree_root = *(++preord_it);
        cur->left = new TreeNode(left_sub_tree_root);
        int mid =  find(inorder.begin(), inorder.end(), left_sub_tree_root) - inorder.begin();
        build(cur->left, ll, mid-1, mid+1, lr, preord_it, inorder);
    }
    if (rl <= rr) {
        int right_sub_tree_root = *(++preord_it);
        cur->right = new TreeNode(right_sub_tree_root);
        int mid = find(inorder.begin(), inorder.end(), right_sub_tree_root) - inorder.begin();
        build(cur->right, rl, mid-1, mid+1, rr, preord_it, inorder);
    }

}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty())
        return nullptr;
    TreeNode* root = new TreeNode(*preorder.begin());
    auto fd = find(inorder.begin(), inorder.end(), root->val);
    int mid = fd-inorder.begin();
    auto inord_it = preorder.begin();
    build(root, 0, mid-1, mid+1, preorder.size()-1, inord_it, inorder);
    return root;
}
int main(){
    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->left->left = new TreeNode(15);
    // root->left->right = new TreeNode(7);
    vector<int> preorder = {3,1,2,4};
    vector<int> inorder = {1,2,3,4};
    buildTree(preorder, inorder);
  return 0;
}