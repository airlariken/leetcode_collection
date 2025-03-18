//
// Created by 橙子味 on 2025/3/13.
//
#include <vector>
using namespace std;

    int findNextLargest1(vector<int> &height, int pos){ //优化后的暴力，还是超时

        int t_height = height[pos];
        int t_index = pos+1;
        for(int i = pos+1; i< height.size(); ++i){
            if(height[i] > t_height){
                t_height = height[i];
                t_index = i;
            }

        }
        return t_index;
    }
    int maxArea1(vector<int>& height) {
        int t_max = 0;
        for(int i = 0; i < height.size(); ++i){
            int j = i;
            while(true){
                j = findNextLargest1(height, j);
                if (j >= height.size())
                    break;
                int mul_res = (j-i)*min(height[i], height[j]);
                if (mul_res > t_max)
                    t_max = mul_res;
            }
        }
        return t_max;
    }

    int maxArea(vector<int>& height) {        //看了题解后，双指针，移动小的那个，有点贪心的想法
        int i = 0, j = height.size()-1;
        int t_max = 0;
        while(i<j){
            int mul_res = (j-i) * min(height[i], height[j]);
            if (mul_res > t_max)
                t_max = mul_res;
            if (height[i] < height[j])  ++i;
            else    --j;

        }
        return t_max;
    }


    #include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<std::vector<int>> data = { {1, 2, 3}, {3, 2, 1} };
    std::set<std::vector<int>> uniqueSet;

    for (auto vec : data) {
        // 如果不考虑顺序，将每个vector排序
        uniqueSet.insert(vec);
    }

    // 输出去重后的数组
    for (const auto& vec : uniqueSet) {
        for (int num : vec)
            std::cout << num << " ";
        std::cout << std::endl;
    }
    return 0;
}

