//
// Created by 橙子味 on 2025/3/14.
//
#include <vector>
using namespace std;


vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    //制造边缘1
    for(int i = 0; i < numRows; ++i){
        res.emplace_back(vector<int>(i+1, 1));
        for(int j = 1; j < i; ++j){
            res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
    }
    return res;
}