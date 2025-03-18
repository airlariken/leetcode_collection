//
// Created by 橙子味 on 2025/3/18.
//
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    dp[0] = 0;
    for(int i = 1; i<= amount; ++i){
        for(auto coin : coins){
            if(i >= coin && dp[i-coin] >= 0){
                if (dp[i] == -1) dp[i] = dp[i-coin] + 1;
                else dp[i] = min(dp[i], dp[i-coin] + 1);
                // cout<<"update"<<i<<'\t'<<dp[i]<<endl;
            }
        }
    }
    return dp[amount];
}