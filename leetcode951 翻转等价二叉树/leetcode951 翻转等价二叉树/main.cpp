//
//  main.cpp
//  leetcode951 翻转等价二叉树
//
//  Created by 陈梓玮 on 2022/7/24.
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
 //自己想的垃圾空间换时间办法，核心思想为确保每个节点的父节点相同，则两颗树相同

// class Solution {
// public:
// map<int,int>lefttree_parent;
// map<int,int>righttree_parent;
//     void traverse(TreeNode* cur, TreeNode* parent, map<int, int>&parent_map){
//         if(cur==nullptr)
//             return;
//             else{
//                 parent_map.insert(pair<int, int>(cur->val, parent->val));
//                 traverse(cur->left, cur, parent_map);
//                 traverse(cur->right, cur, parent_map);
//             }
//     }
//     bool flipEquiv(TreeNode* root1, TreeNode* root2) {
//         TreeNode* root_parent = new TreeNode(); //辅助处理根节点父母不存在的虚拟节点。
//         traverse(root1, root_parent, lefttree_parent);
//         traverse(root2, root_parent, righttree_parent);
//         if (lefttree_parent.size() != righttree_parent.size())      //首先确保两个树是一样大小
//             return false;
//         for(auto it = lefttree_parent.begin(); it != lefttree_parent.end(); ++it){
//             if(it->second != righttree_parent[it->first])
//                 return false;
//         }
//         for(auto it = righttree_parent.begin(); it != righttree_parent.end(); ++it){
//             if(it->second != lefttree_parent[it->first])
//                 return false;
//         }
//         return true;
//     }
// };

//递归法（看了题解），核心思想，比较根节点，根节点相同比较子树，要么翻转相等要么直接相等。
class Solution {
public:

bool subTreeIsEqual(TreeNode* cur_left, TreeNode* cur_right){
    if(cur_left == nullptr && cur_right == nullptr)     //两个都是空指针
        return true;
    else if(!cur_right ||  !cur_left)   //其中一个为空指针
        return false;
    else if(cur_left->val == cur_right->val) //两个节点相等，且不为空，则检查子树翻转后相等或者直接相等
        return (subTreeIsEqual(cur_left->left, cur_right->left) && subTreeIsEqual(cur_left->right, cur_right->right)) || (subTreeIsEqual(cur_left->left, cur_right->right) && subTreeIsEqual(cur_left->right, cur_right->left));
    else return false;       //两个节点不相等
    }


    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return subTreeIsEqual(root1, root2);
    }
   

};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
