//
//  main.cpp
//  leetcode971. 翻转二叉树以匹配先序遍历
//
//  Created by 陈梓玮 on 2022/7/27.
//

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> res;
int  cur_cnt= -1;
    void swap(TreeNode* cur){
        TreeNode* t = cur->left;
        cur->left = cur->right;
        cur->right = t;
        return ;
    }
    bool traverse(TreeNode*cur, vector<int>& voyage){
        
        if(cur == nullptr) return true;
        ++cur_cnt;
        if(cur->val != voyage[cur_cnt]) return false;       //剪枝？

        bool flag = true;
            if(cur->left != nullptr && cur->left->val != voyage[cur_cnt+1]){
                res.push_back(cur->val);
                swap(cur);
            }
        
        flag = flag & traverse(cur->left, voyage);
        flag = flag & traverse(cur->right, voyage);
        return flag;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        bool f = traverse(root, voyage);
        return f == true? res : vector<int>{-1};
    }
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> voyage = {1,2,3};
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout<<flipMatchVoyage(root, voyage)[0];
    std::cout << "Hello, World!\n";
    return 0;
}
