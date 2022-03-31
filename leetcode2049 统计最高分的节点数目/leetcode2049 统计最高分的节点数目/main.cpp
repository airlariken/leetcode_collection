//
//  main.cpp
//  leetcode2049 统计最高分的节点数目
//
//  Created by 陈梓玮 on 2022/3/11.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
//TMD 一直卡在150左右的测试位置，没法debug，发现不了错误，思路很简单但是不知道哪里做错了。。
int countHighestScoreNodes(vector<int>& parents) {
    //维护一个节点个数数组，索引i对应的值为节点i所拥有的子节点个数(包含自己)
    vector<int> node_cnt(parents.size(), 1);
    vector<set<int>> children(parents.size(), set<int>());
    int root = -1;
    for(int i = 0; i < parents.size(); ++i) {
        int father = parents[i];
        if(father == -1){
            root = i;//记录根节点位置
            continue;
        }
        int cur = i;
        while (father != -1) {
            node_cnt[father] += 1;
            children[father].insert(cur);
            cur = father;
            father = parents[father];
        }
    }

    int res = -1;
    int res_cnt = 0;
    for(int i = 0; i < parents.size(); ++i) {
        int t = node_cnt[root] - node_cnt[i];
        for(auto it = children[i].begin(); it != children[i].end(); ++it)
        if(t != 0)
            t *= node_cnt[*it];
        else
            t = node_cnt[*it];
        if(t == res)
            ++res_cnt;
        else if(t > res){
            res = t;
            res_cnt = 1;
        }

    }
    return res_cnt;
}


int main(int argc, const char * argv[]) {
    vector<int> parent = {-1,0,0,1,1, 2,2};
    
    cout<<countHighestScoreNodes(parent)<<endl;
    return 0;
}
