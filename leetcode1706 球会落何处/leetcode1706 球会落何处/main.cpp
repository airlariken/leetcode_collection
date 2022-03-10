//
//  main.cpp
//  leetcode1706 球会落何处
//
//  Created by 陈梓玮 on 2022/2/24.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> findBall(vector<vector<int>>& grid) {
    vector<int> ans(grid[0].size(), -1);
    int cur_ball = 0;
    for(; cur_ball < grid[0].size(); ++cur_ball) {
        int j = cur_ball;//左数第j个球
        int i = 0;
        while (true){
            if(i == grid.size()){
                ans[cur_ball] = j;
                break;
            }

            if(grid[i][j] == 1){        //向右
                if(j+1<grid[0].size() && grid[i][j+1] == 1) {
                    ++i;++j;
                }
                else {ans[cur_ball] = -1;break;}
            }
            else if(grid[i][j] == -1){
                if(j-1>=0 && grid[i][j-1] == -1) {
                    ++i; --j;
                }
                else {ans[cur_ball] = -1;break;}
            }
        }
    }
    return ans;

}

int main(int argc, const char * argv[]) {
    int t_grid[4][6] = {1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1};
    vector<vector<int>> grid(4, vector<int>(6, -1));
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 6; ++j)
            grid[i][j] = t_grid[i][j];
    }
    auto ans = findBall(grid);
    for (auto it : ans)
        cout<<it<<'\t';
    return 0;
}
