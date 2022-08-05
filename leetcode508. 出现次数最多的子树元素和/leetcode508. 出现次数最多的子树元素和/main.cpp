//
//  main.cpp
//  leetcode508. 出现次数最多的子树元素和
//
//  Created by 陈梓玮 on 2022/7/27.
//
//https://leetcode.cn/problems/most-frequent-subtree-sum/
//核心：后序遍历，记录部分和的同时维护最大部分和，map存储每个部分和出现次数
#include <iostream>
#include <map>
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

nt max_cnt = 0;
map<int, int> par_sum_cnt;
    int traverse(TreeNode* cur){
        if(cur==nullptr)    return 0;
        int partial_sum = 0;
        partial_sum+=cur->val;
        partial_sum += traverse(cur->left);
        partial_sum += traverse(cur->right);
        
        auto fi  = par_sum_cnt.find(partial_sum);
        if(fi==par_sum_cnt.end())
            par_sum_cnt[partial_sum] = 0;
        else{
            max_cnt = max(max_cnt, ++par_sum_cnt[partial_sum]);
        }
            
        return partial_sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        traverse(root);
        vector<int>res;
        for(auto it : par_sum_cnt)
            if(it.second == max_cnt)
                res.push_back(it.first);
        return res;
    }
int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-3);
    cout<<findFrequentTreeSum(root)[1];
    std::cout << "Hello, World!\n";
    return 0;
}
