//
//  main.cpp
//  leetcode623 在二叉树中增加一行
//
//  Created by 陈梓玮 on 2022/7/26.
//

#include <iostream>
#include <vector>
#include <queue>
//https://leetcode.cn/problems/add-one-row-to-tree/
//核心思想：双队列相互替换确定广度遍历层数
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
queue<TreeNode*> q1;
queue<TreeNode*> q2;
    void addNode(TreeNode* cur, int val, queue<TreeNode*>& q){
        TreeNode *t1 = cur->left;
        TreeNode* t2 = cur->right;
        cur->left = new TreeNode(val);
        cur->right = new TreeNode(val);
        cur->left->left = t1;
        cur->right->right = t2;
        if(t1 != nullptr)
            q.push(t1);
        if(t2 != nullptr)
            q.push(t2);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        q1.push(root);
        TreeNode* index_node;
        if(depth == 1){
            TreeNode* t = new TreeNode(val);
            t->left = root;
            return t;
        }
        bool stop = 0;
        --depth;
        int cur_depth = 1;
        while(!q1.empty() || !q2.empty()){
            while(!q1.empty()){
                TreeNode* cur = q1.front();  q1.pop();
                if(cur_depth == depth && cur != nullptr){
                    addNode(cur, val, q2);
                    stop = true;
                }
                else{
                    if(cur->left != nullptr)
                        q2.push(cur->left);
                    if(cur->right != nullptr)
                        q2.push(cur->right);
                }
            }
            if(stop == true)
                return root;
            if(!q2.empty())
                ++cur_depth;
            while(!q2.empty()){
                TreeNode* cur = q2.front();  q2.pop();
                if(cur_depth == depth && cur != nullptr){
                    addNode(cur, val, q1);
                    stop = true;
                }
                else{
                    if(cur->left != nullptr)
                        q1.push(cur->left);
                    if(cur->right != nullptr)
                        q1.push(cur->right);
                }
            }
            if(stop == true)
                return root;
            if(!q1.empty())
                ++cur_depth;
        }
        return root;
    }

int main(int argc, const char * argv[]) {
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
