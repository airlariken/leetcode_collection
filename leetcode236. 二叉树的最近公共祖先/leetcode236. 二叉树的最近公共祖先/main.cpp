//
//  main.cpp
//  leetcode236. 二叉树的最近公共祖先
//
//  Created by 陈梓玮 on 2022/7/29.
//

#include <iostream>
#include <stack>
#include<vector>
using namespace std;

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
//方法一：双vector存储两个节点的路径，stack存储当前遍历的路径，存储后按反序找到第一个不同的节点的上一个节点即最近公共祖先
// 效率太低 内存占用太高！
// vector<TreeNode*>p_path;
// vector<TreeNode*>q_path;
// stack<TreeNode*>path;
// TreeNode* p;
// TreeNode* q;
//   void copy_from_stack(vector<TreeNode*>& v, stack<TreeNode*>s){
//         while(!s.empty()){
//             v.insert(v.begin(), s.top());
//             s.pop();
//         }

//     }
//     void traverse(TreeNode* cur){
//         if(cur == nullptr)  return;
//         path.push(cur);
//         if(cur == p)
//             copy_from_stack(p_path, path);
//         else if(cur == q)
//             copy_from_stack(q_path, path);
//         traverse(cur->left);
//         traverse(cur->right);
//         path.pop();
//     }
//     TreeNode* findFirstNode(){
//         int short_path_size = p_path.size()>q_path.size()?q_path.size():p_path.size();
//         for(int i = 0; i < short_path_size; ++i){
//             if (p_path[i] != q_path[i])
//                 return p_path[i-1];
//         }
//         return p_path[short_path_size-1];
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         this->p = p;
//         this->q = q;
//         traverse(root);
//         return findFirstNode();

//     }
TreeNode* p;
TreeNode* q;
bool find = false;
    TreeNode* traverse(TreeNode* cur) {
        if(cur == nullptr) return nullptr;
        TreeNode* left = traverse(cur->left);
        TreeNode* right = traverse(cur->right);
        if(find)    return left==nullptr?right:left;
        if(!(left||right)) {        //双空
            if (cur == p||cur == q)
                return cur;
            else
                return nullptr;
        }
        else if(left&&right){       //两个子节点各有一个，当前节点为祖先
            find = true;
            return cur;
        }
        // else if(left||right){
        else{   //相当于上一行
            if(cur == p || cur == q){        //子节点有一个，当前节点有一个，最近祖先即自己
                find = true;
                return cur;
            }
            else return left==nullptr?right:left;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->q = q;
        this->p = p;
        return traverse(root);


    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->left->left = new TreeNode(6);
    s.lowestCommonAncestor(root, root->left->left, root->right);
    std::cout << "Hello, World!\n";
    int * p1=  NULL;
    int * p2 = nullptr;
    
    return 0;
}
