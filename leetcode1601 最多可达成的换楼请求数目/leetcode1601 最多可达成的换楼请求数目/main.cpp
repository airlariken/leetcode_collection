//
//  main.cpp
//  leetcode1601 最多可达成的换楼请求数目
//
//  Created by 陈梓玮 on 2022/2/28.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    int zeros;
    vector<int> offset;
    int res = 0;
    int t_res = 0;
    
public:

    void DFSBacktracking(int cur, vector<vector<int>>& requests)
    {
        if(zeros == offset.size() && res < t_res){
            res = t_res;
            cout<<res<<endl;
        }
        if(cur != requests.size()){
            //不选择该节点
            DFSBacktracking(cur+1, requests);
            //选择该节点
            ++t_res;
            int out = requests[cur][0];
            int in = requests[cur][1];
            int t_zero = zeros;
            
            //这个判断太他吗坑了沃日浪费我一下午！！！！
            if(offset[out] == 0)
                --zeros;
            if(--offset[out] == 0)
                ++zeros;
            if(offset[in] == 0)
                --zeros;
            if(++offset[in] == 0)
                ++zeros;
            
            DFSBacktracking(cur+1, requests);
            
            //回溯复原现场
            zeros = t_zero;
            --offset[in];
            ++offset[out];
            --t_res;
        }
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
    //DFS回溯法枚举所有可能性
        if(requests.size() == 0)
            return 0;
        offset.resize(n, 0);
        zeros = n;
        DFSBacktracking(0, requests);
        return res;
    }
};

int main()
{
    Solution s;
    
//    int arr[] = {0,1,1,0,0,1,1,2,2,0,3,4};
    
//    int arr[] = {1,1,1,0,0,1,0,0,0,0,0,1,0,1,1,0,1,0,1,1,0,0,1,0};
    int arr[] = {1,1 ,1,0 ,0,1 ,0,0 ,0,0 ,0,1 ,0,1 ,1,0/* ,1,0/* ,1,1,0,0,1,0*/};
//    int arr[] = {1,2,1,2,2,2,0,2,2,1,1,1,1,2};
    vector<vector<int>> request(sizeof(arr)/sizeof(int)/2, vector<int>(2, 0));
    
    for(int i = 0; i < sizeof(arr)/sizeof(int); ++i){
        request[i/2][i%2] = arr[i];
    }
    cout<<s.maximumRequests(2, request)<<endl;
}

