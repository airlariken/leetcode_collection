//
//  main.cpp
//  leetcode794 有效的井字游戏
//
//  Created by 陈梓玮 on 2021/12/11.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool validTicTacToe(vector<string>& board) {
    if (board.size()!=3)
        return false;
    for (int i = 0; i < 3; ++i){
        if(board[i].length() !=3 )
            return false;
    }
    
    vector<vector<int>>chess(3, vector<int>(3, 0));
    int valid_cnt = 0;
    for (int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j) {
            if(board[i][j] == ' ')
                continue;
            else if(board[i][j] == 'X') {
                chess[i][j] = 1;        //黑棋先手， 为1
                ++valid_cnt;
            }
                
            else{
                chess[i][j] = -1;       //白棋-1
                --valid_cnt;
            }
            
            
        }
    }
    if(valid_cnt < 0|| valid_cnt > 1)
        return false;
    int isWin = false;
    for (int i = 0; i < 3; ++i){
        if(chess[i][0] + chess[i][1]+chess[i][2] == 3){
            if(isWin >= 0)
                isWin = 1;
            else
                return false;
        }
        else if(chess[i][0] + chess[i][1]+chess[i][2] == -3){
            if(isWin <= 0)
                isWin = -1;
            else
                return false;       //不能有两个方向同时赢
        }
        else if(chess[0][i] + chess[1][i]+chess[2][i] == 3){
            if(isWin >= 0)
                isWin = 1;
            else
                return false;
        }
        else if(chess[0][i] + chess[1][i]+chess[2][i] == -3){
            if(isWin <= 0)
                isWin = -1;
            else
                return false;       //不能有两个方向同时赢
        }
        else if(chess[0][0]+chess[1][1]+chess[2][2] == 3){
            if(isWin >= 0)
                isWin = 1;
            else
                return false;       //不能有两个方向同时赢
        }
        else if(chess[0][0]+chess[1][1]+chess[2][2] == -3) {
            if(isWin <= 0)
                isWin = -1;
            else
                return false;       //不能有两个方向同时赢
        }
        
        else if(chess[2][0]+chess[1][1]+chess[0][2] == 3){
            if(isWin >= 0)
                isWin = 1;
            else
                return false;       //不能有两个方向同时赢
        }
        else if(chess[2][0]+chess[1][1]+chess[0][2] == -3){
            if(isWin <= 0)
                isWin = -1;
            else
                return false;       //不能有两个方向同时赢
        }
        
    }
    if (isWin == 1){
        if(valid_cnt!= 1)
            return false;
    }
    if (isWin == -1) {
        if (valid_cnt != 0) {
            return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    // insert code here...

    
    vector<string> board = {    "XOX","OOX","XO "};
    cout<<validTicTacToe(board);
    return 0;
}
