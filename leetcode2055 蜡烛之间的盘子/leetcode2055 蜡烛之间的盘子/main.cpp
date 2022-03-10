//
//  main.cpp
//  leetcode2055 蜡烛之间的盘子
//
//  Created by 陈梓玮 on 2022/3/8.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    vector<int> candle_pos;
    vector<int> res;
    for(int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '|'){
            candle_pos.push_back(i);
        }
    }
    for(int i = 0 ; i < queries.size(); ++i){
        auto f1 = lower_bound(candle_pos.begin(), candle_pos.end(), queries[i][0]);
        if(f1 == candle_pos.end()){
            res.push_back(0);
            continue;
        }
        auto f2 = lower_bound(candle_pos.begin(), candle_pos.end(), queries[i][1]);
        if(f1 == candle_pos.end()){
                res.push_back(0);
            continue;
        }
        else if(*f2 != queries[i][1] && f2 != candle_pos.begin()){
                --f2;
        }
        int candle_in_total = f2 - f1 + 1;
        int t_res = *f2 - *f1 - candle_in_total + 1;
        if(t_res <= 0){
            res.push_back(0);
            continue;
        }
        res.push_back(t_res);

    }
    return res;
}


int main(int argc, const char * argv[]) {
    
//    string s = "***|**|*****|**||**|*";
//    int t[] = {1,17,4,5,14,17,5,11,15,16};
//    string s = "**|**|***|";
//    int t[] = {2,5,5,9};
    string s = "*|*|||";
    int t[] = {0,0,1,3};

    
    vector<vector<int>> queries;
    for(int i = 0; i < (sizeof(t)/sizeof(int))/2; ++i){
        vector<int> t_v;
        for(int j = 0; j < 2; ++j){
            t_v.push_back(t[i*2+j]);
        }
        queries.push_back(t_v);
    }
    auto res = platesBetweenCandles(s, queries);
    for (auto it : res)
        cout<<it<<'\t';
    return 0;
}
