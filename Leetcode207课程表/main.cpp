//
// Created by 橙子味 on 2025/3/13.
//
/*
TMD花了一整个下午+吃饭时间弄明白了，dfs判断有向图带环不能只靠visited数组，需要一个on_stack数组存储当前stack中元素
确保一个dfs搜索内任一节点仅在on_stack中出现一次，而不是一个dfs搜索内任一节点仅能被看到一次
 */
#include <vector>
using namespace std;

class Solution {
    vector<bool> visited;
    vector<bool> on_stack;
    bool has_cycle = false;
    vector<vector<int>> edges;
public:
    void dfs(int cur){
        visited[cur] = true;
        on_stack[cur] = true;
        for (int neib : edges[cur]){
            if (on_stack[neib] == true){
                has_cycle = true;
                return;
            }
            if (visited[neib] == false)
                dfs(neib);
        }
        on_stack[cur] = false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses, false);
        on_stack.resize(numCourses, false);
        for (auto it : prerequisites)
            edges[it[1]].emplace_back(it[0]);

        for (int i = 0; i < numCourses; ++i){
            if (!visited[i])
                dfs(i);
        }
        return !has_cycle;
    }
};