//
// Created by 橙子味 on 2025/3/17.
//
#include <iostream>
#include <ostream>
#include<string>
#include<vector>
#include<stack>
#include <unordered_set>
using namespace std;
#include <iostream>
bool wordBreakOld(string s, vector<string>& wordDict) { //超时，感觉应该是正确的
  stack<int> pos_s;
  pos_s.push(0);
  while(!pos_s.empty()){
    int pos = pos_s.top(); pos_s.pop();
    // cout<<pos<<'\t';
    if (pos == s.length())  return true;
    for (auto words: wordDict)
      if (s.length()-pos >= words.length() && s.substr(pos, words.length()) == words) {
        pos_s.push(pos+words.length());
      }
  }
  return false;
}
bool wordBreak(string s, vector<string>& wordDict) {    //加了个hash就不超时了
  unordered_set<string> hash;
  for(auto word : wordDict)
    hash.insert(word);
  vector<bool> dp(s.length()+1, 0);
  dp[0] = true;
  for(int i = 1; i < s.length()+1; ++i){
    for(auto it : hash){
      if(i >= it.length() && dp[i-it.length()] == true && s.substr(i-it.length(), it.length()) == it) {
        dp[i] = true;
      }
    }
  }
  return dp[dp.size()-1];
}
int main(){
  string s = "applepenapple";
  string apple = "apple";
  string pen = "pen";
  if (s.substr(8-pen.length(), pen.length())  == pen) {
    cout << s.substr(8-pen.length(), pen.length())  << endl;

  }
}