//
//  main.cpp
//  leetcode1578. 避免重复字母的最小删除成本
//
//  Created by 陈梓玮 on 2021/4/5.
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    vector<int>cost;
//    string s("aaabbbabbbb");
//    cost.push_back(3);
//    cost.push_back(5);
//    cost.push_back(10);
//    cost.push_back(7);
//    cost.push_back(5);
//    cost.push_back(3);
//    cost.push_back(5);
//    cost.push_back(5);
//    cost.push_back(4);
//    cost.push_back(8);
//    cost.push_back(1);
//    string s("aaaaaaaaaa");
//    cost.push_back(9);
//    cost.push_back(3);
//    cost.push_back(9);
//    cost.push_back(8);
//    cost.push_back(8);
//    cost.push_back(3);
//    cost.push_back(2);
//    cost.push_back(7);
//    cost.push_back(6);
//    cost.push_back(6);

    

//    int cur = 0;
//    bool *delete_pos = new bool[cost.size()];
//    for(int i = 0 ; i < cost.size(); ++i)  delete_pos[i] = 0;//initializtion
//    int totalcost = 0;
//    while(s[cur] != '\0'){
//        int next = 1;
//        while(s[cur] != '\0' && delete_pos[cur] == 1)cur++;
//        while(s[cur+next] != '\0' && delete_pos[cur+next] == 1)next++;
//        if(s[cur] == s[cur+next]){//出现重复，删除cost少的那个
//             if(cost[cur]<=cost[cur+next]){
//                cout<<cur<<'\t';
//                totalcost+=cost[cur];
//                delete_pos[cur]=1;
////                cur--;
//
//             }
//            else{
//                cout<<cur+next<<'\t';
//                totalcost+=cost[cur+next];
//                delete_pos[cur+next]=1;
//            }
//        }
//        else{
//            cur+=next;
//        }
//
//    }
    
    
    string s("abaac");
    cost.push_back(1);
    cost.push_back(2);
    cost.push_back(3);
    cost.push_back(4);
    cost.push_back(5);
    
    
    int index1 = 0;
    int totalcost = 0;
    while(s[index1] != '\0'){
        totalcost += cost[index1];
        int t = 1;
        int max = cost[index1];
        char tempchar = s[index1];
            while(s[index1+t] != '\0' && s[index1+t] == tempchar) {
                totalcost += cost[index1+t];
                if (cost[index1+t] > max)
                    max = cost[index1+t];
                t++;
        }
        index1 = index1+t;
        totalcost -= max;
    }
    cout<<totalcost;
}
