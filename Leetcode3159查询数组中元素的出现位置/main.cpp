//
// Created by 橙子味 on 2024/12/27.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool find_next_x(const vector<int> &nums,map<int, int> &occurr_pos, int x) {
    int now_pos;
    if (occurr_pos.empty())
        now_pos = 0;
    else
        now_pos = occurr_pos.rbegin()->second+1;
    for (auto i = now_pos; i < nums.size(); i++) {
        if (nums[i] == x) {
            occurr_pos.insert(make_pair(occurr_pos.size()+1, i));
            return true;
        }
    }
    return false;
}
vector<int> occurrencesOfElement1(vector<int>& nums, vector<int>& queries, int x) {
    vector<int> result;
    map<int, int> occurr_pos;
    for (int i = 0; i < queries.size(); i++) {
        int query_t = queries[i];
        while (occurr_pos.find(query_t) == occurr_pos.end()) {
            bool flag = find_next_x(nums, occurr_pos, x);
            if (!flag)
                break;
        }
        auto find = occurr_pos.find(query_t);
        if (find != occurr_pos.end()) {
            result.push_back(find->second);
        }
        else
            result.push_back(-1);
    }
    return result;
}

vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
    vector<int> result;
    vector<int> index;
    auto max_q_it = max_element(queries.begin(), queries.end());
    int max_query = *max_q_it;
    for (int i = 0; i < nums.size(); i++) {
        if (index.size() >= max_query) {
            break;
        }
        if (nums[i] == x)
            index.push_back(i);
    }
    for (auto x:queries)
        result.push_back(x>=index.size() ? -1: index[x-1]);
    return result;
}

int main()
{
    vector<int> nums = {1,3,1,7};
    vector<int> queries = {1,3,2,4};
    vector<int> result = occurrencesOfElement(nums, queries, 1);
    for (auto x : result) {
        cout<<x<<endl;
    }


}