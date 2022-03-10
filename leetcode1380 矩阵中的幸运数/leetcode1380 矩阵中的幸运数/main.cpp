//
//  main.cpp
//  leetcode1380 矩阵中的幸运数
//
//  Created by 陈梓玮 on 2022/2/15.
//

#include <iostream>
#include <vector>
using namespace std;


vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> res;
    
    for(int i = 0; i < matrix.size(); ++i){
        int row_min = INT_MAX;
        int row_min_pos = -1;
        for (int j = 0; j < matrix[0].size(); ++j){
            if (row_min > matrix[i][j]){
                row_min = matrix[i][j];
                row_min_pos = j;    //位于第j列
            }
        }
        int col_max = row_min;
        for (int k = 0; k < matrix.size() ; ++ k){
            //检索第j列
            if (col_max < matrix[k][row_min_pos]){
                col_max = matrix[k][row_min_pos];
                break;
            }
        }
        if (col_max == row_min)
            res.push_back(col_max);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix(3, vector<int>());
    matrix[0].assign({1,10,4,2});
    matrix[1].assign({9,3,8,7});
    matrix[2].assign({15,16,17,12});
    luckyNumbers(matrix);
    
    return 0;
}
