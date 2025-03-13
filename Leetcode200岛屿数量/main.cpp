//
// Created by 橙子味 on 2025/3/13.
//
#include <vector>
using namespace std;

bool dfs(vector<vector<char>> &grid, int x, int y){

    if (!(x>=0 && y>=0 && x< grid.size() && y < grid[x].size()))
        return false;   //越界

    if (grid[x][y] == '0')  return false;
    else{
        grid[x][y] = '0';
        dfs(grid, x-1, y);
        dfs(grid, x+1, y);
        dfs(grid, x, y-1);
        dfs(grid, x, y+1);
        return true;
    }

}
int numIslands(vector<vector<char>>& grid) {
    int cnt = 0;
    for (int x = 0; x < grid.size(); ++x){
        for (int y = 0; y < grid[x].size(); ++y){
            if (grid[x][y] == '1' && dfs(grid, x, y))
                ++cnt;
        }
    }
    return cnt;
}
