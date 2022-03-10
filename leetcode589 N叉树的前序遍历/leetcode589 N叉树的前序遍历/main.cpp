//
//  main.cpp
//  leetcode589 N叉树的前序遍历
//
//  Created by 陈梓玮 on 2022/3/10.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
//前序遍历
vector<int> res;
inline void preorderSubFun(Node *cur){
    if (cur == nullptr)
        return ;
    res.emplace_back(cur->val);
    for(auto it : cur->children){
        preorderSubFun(it);
    }
}
vector<int> preorder(Node* root) {
    preorderSubFun(root);
    return res;
}

// 层序遍历
//vector<int> levelorder(Node* root) {
//    queue<Node*> q;
//    q.push(root);
//    vector<int> res;
//    while(!q.empty()){
//        Node* cur = q.front(); q.pop();
//        res.push_back(cur->val);
//        vector<Node*> nice = cur->children;
//        for(auto it : cur->children)
//            q.push(it);
//
//    }
//    return res;
//
//}

int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    return 0;
}
