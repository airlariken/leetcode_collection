//
// Created by 橙子味 on 2025/2/18.
//

#include <algorithm>
#include <iostream>
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
void visit(TreeNode* cur, int targetSum, vector<long long int> cur_sum, int& res){
  if (cur == nullptr) return ;
  for (auto& it : cur_sum){
    it += cur->val;
    if (it  == targetSum)
      ++res;
  }
  if (cur->val == targetSum) ++res;
  cur_sum.emplace_back(cur->val);
  visit(cur->left, targetSum, cur_sum, res);
  visit(cur->right, targetSum, cur_sum, res);
  // visit(cur->left, targetSum, cur->val, res);
  // visit(cur->right, targetSum, cur->val, res);
}

int main(){
  cout<<"Hello World"<<endl;
}