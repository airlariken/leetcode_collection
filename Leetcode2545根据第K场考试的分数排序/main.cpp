//
// Created by 橙子味 on 2024/12/24.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    map<int, int> m;
    for (auto it = score.begin(); it != score.end(); it++) {
      m.insert(make_pair((*it)[k], it-score.begin()));
    }
    vector<vector<int>> res;
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
      cout<<it->first<<" "<<it->second<<endl;
      res.push_back(score[it->second]);
    }
    return res;
}

int main(){
  vector<vector<int>> score = {
    {4, 8, 3, 15},
    {10, 6, 9, 1},
    {7, 5, 11, 2}
  };

  sortTheStudents(score,2);
  }