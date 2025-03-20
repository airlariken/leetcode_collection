//
// Created by 橙子味 on 2025/3/20.
//
#include <vector>
using namespace std;

class Solution {
    bool inline isValid(int x, int y, vector<vector<bool>> &visited, vector<vector<char>> &board){
        return x>=0 && y >= 0 && x < board.size() && y < board[x].size() && visited[x][y] == false;
    }
public:
    bool dfs(int cur, int x, int y, vector<vector<bool>> &visited, vector<vector<char>>& board, string word){
        if (board[x][y] == word[cur]){
            ++cur;
            if (cur==word.length()) return true;
            bool flag = false;
            visited[x][y] = true;
            if(isValid(x+1, y, visited, board)) flag |= dfs(cur, x+1, y, visited, board, word);
            if(isValid(x-1, y, visited, board)) flag |= dfs(cur, x-1, y, visited, board, word);
            if(isValid(x, y+1, visited, board)) flag |= dfs(cur, x, y+1, visited, board, word);
            if(isValid(x, y-1, visited, board)) flag |= dfs(cur, x, y-1, visited, board, word);
            visited[x][y] = false;          //最关键的，要回溯！
            return flag;
        }
        else{
            return false;
        }


    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        if (board.size() == 0) return false;
        for(int i = 0; i< board.size(); ++i){
            for (int j = 0; j < board[i].size(); ++j){
                vector<vector<bool>> visited(board.size(), vector<bool>(board.begin()->size()));
                if (dfs(0, i, j, visited, board, word))
                    return true;
            }
        }
        return false;
    }
};