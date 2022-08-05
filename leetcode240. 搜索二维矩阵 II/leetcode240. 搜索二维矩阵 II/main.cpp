//
//  main.cpp
//  leetcode240. 搜索二维矩阵 II
//
//  Created by 陈梓玮 on 2022/8/4.
//https://leetcode.cn/problems/search-a-2d-matrix-ii/

#include <iostream>
#include <vector>
using namespace std;

//方法1：逐行二分查找遍历

//inline bool row_worker(vector<vector<int>>& matrix, int row, int target){
//    int left = 0;
//    int right = matrix[row].size()-1;
//    while(left<=right){
//        int mid = (left+right)/2;
//        if(matrix[row][mid]==target)   return true;
//        if(matrix[row][mid] < target)
//            left = mid + 1;
//        else    right = mid-1;
//    }
//    return false;
//}
//bool searchMatrix(vector<vector<int>>& matrix, int target) {
//    for(int i = 0; i < matrix.size(); ++i){
//        if(row_worker(matrix, i, target) == true)
//            return true;
//    }
//    return false;
//}

// 方法2：BST查找思想，ps:去掉递归速度更快（递归很慢）

     bool traverse(vector<vector<int>>& matrix, int m, int n, int target){
         if(m>=matrix.size() || n < 0)    return false;
         // cout<<matrix[m][n]<<'\t';
         if(matrix[m][n]== target)   return true;
         if(matrix[m][n]>target) { //去左子树查
             return traverse(matrix, m, n-1, target);
         }
         else{ //右子树查
             return traverse(matrix, m+1, n, target);
         }
     }
     bool searchMatrix(vector<vector<int>>& matrix, int target) {
         return traverse(matrix,0 , matrix.begin()->size()-1, target);
     }



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
