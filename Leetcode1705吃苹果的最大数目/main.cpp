//
// Created by 橙子味 on 2024/12/26.
//
#include <iostream>
using namespace std;
#include <map>
#include <set>
#include <vector>
#include <algorithm>
int eatenApples1(vector<int>& apples, vector<int>& days) {
    map<int,int> apples_due;
    int res = 0;
    int cur_day = 0;
//        int cur_apple = 0;

    while (!apples_due.empty() || cur_day <= days.size()) {
//          cur_apple += apples[cur_day];
        if (cur_day<days.size() && apples[cur_day] > 0) {
            if (apples_due.find(days[cur_day]) != apples_due.end())
                apples_due[days[cur_day]] += apples[cur_day];
            else apples_due[days[cur_day]] = apples[cur_day];
        }


        auto it = apples_due.begin();
        int tmp = 0;
        if (it != apples_due.end()) {
            //吃掉一个
            tmp = min(it->first, it->second);
            apples_due.erase(it);
            res+=tmp;

        }
        else
            tmp = 1;//没吃

        apples_due.erase(apples_due.begin(), apples_due.upper_bound(tmp));      //清除过期不要的


        for (auto it = apples_due.begin(); it != apples_due.end();) {
            int apple = it->second;
            int n_day = tmp;
            int day = it->first-n_day;
            it = apples_due.erase(it);
            if (day > 0)
                apples_due.insert(make_pair(day, apple));
        }

        for (int i = cur_day+1; i < min(cur_day+tmp, static_cast<int>(days.size())); i++) {
            if (days[i]-cur_day> tmp)
            apples_due[(days[i]-cur_day) - tmp] += apples[i];
        }
        cur_day+=tmp;


//          --cur_apple;

    }
    return res;
}
// #include <queue>
// int eatenApples(vector<int>& apples, vector<int>& days) {
//     priority_queue<pair<int,int>,vector<pair<int, int>>, greater<>> apples_due;
//
//     int res = 0;
//     int cur_day = 0;
//     //        int cur_apple = 0;
//
//     while (!apples_due.empty() || cur_day <= days.size()) {
//         //          cur_apple += apples[cur_day];
//         if (cur_day<days.size() && apples[cur_day] > 0) {
//             apples_due.push(make_pair(days[cur_day], apples[cur_day]));
//         }
//
//
//
//         if (!apples.empty() ) {
//             auto it = apples_due.top();
//             //吃掉一个
//             if (it.second - 1 != 0)
//                 it.second -= 1;
//             else
//                 apples_due.pop();
//             ++res;
//         }
//         else
//             ;//没吃
//
//
//         for (auto it = apples_due.begin(); it != apples_due.end();) {
//             int apple = it->second;
//             int day = it->first-1;
//             it = apples_due.erase(it);
//             if (day > 0)
//                 apples_due.insert(make_pair(day, apple));
//         }
//         //          --cur_apple;
//         ++cur_day;
//     }
//     return res;
// }

int main(){
    vector<int> apples = {1,10,17,10,12,6,20,8,8,22,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,5,2,1,0,0,0,0,0,0,23};
    vector<int> days = {19999,11,18,22,5,2,14,5,20,7,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,2,1,4,2,7,0,0,0,0,0,0,1};
    int res = eatenApples1(apples, days);
    cout<<res;
  }
