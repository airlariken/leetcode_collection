//
//  main.cpp
//  leetcode210课程表 II
//
//  Created by 陈梓玮 on 2022/7/21.
// https://leetcode.cn/problems/course-schedule-ii/

//求解时间&空间复杂度太高，待优化
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<int>& getNodeList(int u, map<int, vector<int>>& edge_map){
    auto fi = edge_map.find(u);
    if (fi != edge_map.end())  { //找到了
        return fi->second;
    }
    auto ele = edge_map.insert(pair<int, vector<int>>(u, vector<int>()));
    return ele.first->second;       //返回刚刚新建出来的vector
}
bool bfs(int u, int target, map<int, vector<int>>& edge_map, int num){
    queue<int> m_queue;
    m_queue.push(u);
    bool* visited = new bool[num];
    memset(visited, 0 , num*sizeof(bool));
    while(!m_queue.empty()){
        int cur_ele = m_queue.front();    m_queue.pop();
        visited[cur_ele] = true;
        if(cur_ele == target)
            return true;
        auto fi = edge_map.find(cur_ele);
        if(fi!= edge_map.end()){
            for(auto i : fi->second)
                if(visited[i]==false)
                    m_queue.push(i);
        }
    }
    return false;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    if (numCourses == 1)
    return vector<int>{0};
    map<int, vector<int>> edge_map;
    queue<int>m_queue;
    int* indegree = new int [numCourses];
    memset(indegree, 0, numCourses*sizeof(int));
    for(auto i : prerequisites){
        vector<int>& node_list = getNodeList(i[0],edge_map);        //这里不引用就寄了，&很重要
        if(bfs(i[1], i[0], edge_map, numCourses))      //如果原先就成环了那直接结束
            return vector<int>();
        node_list.push_back(i[1]);
        ++indegree[i[1]];
    }
    bool* visited = new bool[numCourses];                //是否剔除
    memset(visited, 0, numCourses*sizeof(bool));        //ini
    vector<int> res;                                    //结果数组
    int cnt = 0;
    while(cnt < numCourses){
        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] == 0 && visited[i] == false){
                ++cnt;
                visited[i] = true;
                res.push_back(i);
                auto fi = edge_map.find(i);
                if(fi != edge_map.end()){         //如果有邻接节点
                    auto node_list  = fi->second;
                    for(auto x : node_list)
                        --indegree[x];
                
                }
            }
        }
    }
    // for(auto i = edge_map.begin(); i != edge_map.end();++i){
    //     for(auto j : i->second)
    //         cout<<i->first<<"->"<<j<<'\t';
    //     cout<<endl;
    // }
    reverse(res.begin(), res.end());       //翻转一下
    return res;

}
    

int main(int argc, const char * argv[]) {
    map<int, vector<int>> edge_map;
    vector<vector<int>> prerequisites;

    prerequisites.push_back(vector<int>());
    prerequisites.begin()->push_back(1);
    prerequisites.begin()->push_back(0);
    
    prerequisites.push_back(vector<int>());
    (--prerequisites.end())->push_back(0);
    (--prerequisites.end())->push_back(1);
    
    
    findOrder(2, prerequisites);
    return 0;
}
