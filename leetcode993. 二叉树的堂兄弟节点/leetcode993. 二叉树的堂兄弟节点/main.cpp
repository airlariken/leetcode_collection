//
//  main.cpp
//  leetcode993. 二叉树的堂兄弟节点
//
//  Created by 陈梓玮 on 2022/7/27.
//

#include <iostream>
#include <queue>
// https://leetcode.cn/problems/cousins-in-binary-tree/submissions/
// 核心思想，单队列，第二个元素int用于记录层数，保证两个节点同一层的同时，不是同一个父母，也即不是正好属于cur->right cur->left
using namespace  std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


using makepair = pair<TreeNode*, int>;
queue<pair<TreeNode*, int>> q;
vector<int> dep;
    bool Traverse(TreeNode* root, int x, int y){
        q.push(makepair(root, 0));
        while(!q.empty()){
            TreeNode* cur = q.front().first;   int depth = q.front().second; q.pop();
            int is_brother=0;
            if(cur->left!=nullptr){
                q.push(makepair(cur->left,depth+1));
                if(cur->left->val == x || cur->left->val == y){
                    ++is_brother;
                    dep.push_back(depth+1);
                }
            }
            
            if(cur->right!=nullptr){
                q.push(makepair(cur->right,depth+1));
                if(cur->right->val == x || cur->right->val == y){
                    ++is_brother;
                    dep.push_back(depth+1);
                }
            }
            if(is_brother == 2) //单次循环就找到两个说明必是brother
                return false;
            
        }
        if(dep.size() == 2 && dep[0] == dep[1])
            return true;
        else    return false;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        return Traverse(root, x, y);
    }
int main(int argc, const char * argv[]) {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    cout<<isCousins(root, 4,5)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
