//
// Created by 橙子味 on 2025/1/14.
//
// 这道题直接在leetcode做的
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
class Solution {
public:

    void visit_helper(TreeNode* cur, int level, vector<vector<int>> &res){
        if (cur == nullptr) return;
        if(res.size() <= level) res.emplace_back(vector<int>());
        res[level].emplace_back(cur->val);
        visit_helper(cur->left, level+1, res);
        visit_helper(cur->right, level+1, res);
    }
    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> res;
        visit_helper(root, 0, res);
        return res;
    }


    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        q1.push(root);
        vector<int> temp;
        vector<vector<int>> res;
        while(!q1.empty() || !q2.empty()){
            auto cur = q1.front();q1.pop();
            if(cur!= nullptr){
                temp.emplace_back(cur->val);
                q2.push(cur->left);
                q2.push(cur->right);
            }
            if(q1.empty()){
                swap(q1,q2);
                if (!temp.empty()){
                    res.emplace_back(std::move(temp));
                    temp = vector<int>();
                }

            }


        }
        return res;
    }
};