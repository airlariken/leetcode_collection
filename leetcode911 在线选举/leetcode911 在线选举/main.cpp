//
//  main.cpp
//  leetcode911 在线选举
//
//  Created by 陈梓玮 on 2021/12/11.
//

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> time_res;
int pre;
vector<int> p_times;
unordered_map<int, int> res;//第一个是选手编号，第二个是该选手得票数
void TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    p_times = times;
    if(persons.size()== 0)
        return;
//    if(res.find(persons[0]) == res.end())
//        ++res[persons[0]];
//    else
    res[persons[0]] = 1;
    pre = persons[0];
    time_res.push_back(pre);
    for(int i = 1; i < persons.size(); ++i) {
        if(res.find(persons[i]) != res.end())
            ++res[persons[i]];
        else
            res[persons[i]] = 1;
        if(res[persons[i]] >= res[pre])
            pre = persons[i];
        time_res.push_back(pre);
    }
    
}

int q(int t) {
    auto it = upper_bound(p_times.begin(), p_times.end(), t);
    auto pos = it - p_times.begin() - 1;
//    auto cnt =it  - p_times.begin() + 1;
//    int pos = distance(it, time_res.begin());
//    return time_res[cnt];
    return time_res[pos];
}


int main(int argc, const char * argv[]) {
    vector<int> persons{0, 1, 1, 0, 0, 1, 0};
    vector<int> times{0, 5, 10, 15, 20, 25, 30};
    vector<int> qes{3, 12, 25, 15, 24, 8};
    
    TopVotedCandidate(persons, times);
    for(auto it:qes)
        cout<<q(it)<<endl;
    
    return 0;
}
