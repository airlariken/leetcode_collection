//
// Created by 橙子味 on 2025/3/13.
// shit 中 shit代码，找机会重写。。。
#include<vector>
#include<queue>
using namespace std;

inline bool checkValid(vector<vector<int>>& grid, int x, int y){
    return x>=0 && y >=0 && x<grid.size() && y < grid[x].size() && grid[x][y] == 1;
}
void findRot(vector<vector<int>>& grid, vector<pair<int, int>> &rot_vec){
    for (int x = 0; x<grid.size(); ++x){
        for (int y = 0; y < grid[x].size(); ++y){
            if (grid[x][y] == 2)
            rot_vec.emplace_back(make_pair(x,y));
        }
    }
}
bool checkFresh(vector<vector<int>>& grid, bool& _hasOrnage){
     _hasOrnage = false;
    for (int x = 0; x<grid.size(); ++x){
        for (int y = 0; y < grid[x].size(); ++y){
            if (grid[x][y] != 0)
                _hasOrnage = true;
            if (grid[x][y] == 1)
                return true;
        }
    }
    return false;
}
int bfs(vector<vector<int>>& grid){
    vector<pair<int, int>> rot_or_vec;
    findRot(grid, rot_or_vec);
    queue<pair<int, int>> q, q_buf;
    for (auto it : rot_or_vec){
        q.push(make_pair(it.first, it.second));
    }
    int cnt = 0;
    while(!q.empty() || !q_buf.empty()){
        auto xypair = q.front(); q.pop();
        int x = xypair.first;
        int y = xypair.second;

        if (checkValid(grid, x+1, y)) {
            q_buf.push(make_pair(x+1, y));
            grid[x+1][y] = 2;
        }
        if (checkValid(grid,x-1, y)) {
            q_buf.push(make_pair(x-1, y));
            grid[x-1][y] = 2;
        }

        if (checkValid(grid,x, y+1)) {
            q_buf.push(make_pair(x, y+1));
            grid[x][y+1] = 2;
        }
        if (checkValid(grid,x, y-1)) {
            q_buf.push(make_pair(x, y-1));
            grid[x][y-1] = 2;
        }
        if (q.empty()){
            swap(q, q_buf);
            ++cnt;
        }
    }
    return cnt;
}
int orangesRotting(vector<vector<int>>& grid) {
    int cnt = bfs(grid);
    bool has_orange;
    if (checkFresh(grid, has_orange))
        if  (has_orange == true)
            return -1;
    return cnt > 0?  cnt-1 : cnt;
}

int main(){

  }