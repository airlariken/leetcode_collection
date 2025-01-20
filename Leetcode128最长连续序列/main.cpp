//
// Created by 橙子味 on 2024/12/24.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int longestConsecutive(vector<int>& nums) {
  if (nums.size()<=1) return nums.size();
  sort(nums.begin(), nums.end());
  bool is_continue = true;
  int cnt = 1;
  int res = cnt;
  for (auto it = ++nums.begin(); it != nums.end(); ++it) {
    if (it != nums.end()) {
      if ( *it - *(it-1) == 1) {
        is_continue = true;
        ++cnt;
      }
      else if (*it == *(it-1) ) continue;
      else {
        is_continue = false;
        cnt = 1;
      }
      if (res<cnt) res=cnt;
    }
  }
  return res;
}

int main(){
  vector<int> nums1 = {0,3,7,2,5,8,4,6,0,1};
  // longestConsecutive(nums1);
  cout<<longestConsecutive(nums1)<<endl;
  printf("Hello World\n");
  return 0;
}