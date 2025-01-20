//
// Created by 橙子味 on 2024/12/30.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  // Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool search(TreeNode *root, ListNode *head) {
  if (head == nullptr) return true;
  if (root == nullptr) return false;
  if (root->val == head->val)
    return search(root->left, head->next) || search(root->right, head->next);
  return false;
}


bool preorderTraversal(TreeNode *root, ListNode *head) {
  if (root == nullptr) return false;
  bool flag = false;
  if (root->val == head->val)
    flag = search(root, head);
  if (flag) return true;
  return preorderTraversal(root->left, head) || preorderTraversal(root->right, head);
}
int main()
{
  ListNode *head = new ListNode(1);
  TreeNode *root = new ListNode(1);
  vector<int> nums{1,2,3,4,5,6,7,8,9};
  cout<<nums.size()<<endl;
}