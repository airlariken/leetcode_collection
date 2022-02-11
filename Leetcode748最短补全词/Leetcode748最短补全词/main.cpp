//
//  main.cpp
//  Leetcode748最短补全词
//
//  Created by 陈梓玮 on 2021/12/11.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;



string shortestCompletingWord(string licensePlate, vector<string>& words) {
    vector<int>char_arr(26,0);
    multimap<int, string>res;
    for( auto it = licensePlate.begin(); it != licensePlate.end(); ++it)
    {
        if (*it >='a'&& *it <= 'z'){
            ++char_arr[*it-'a'];
        }
        else if (*it >='A'&& *it <= 'Z'){
            ++char_arr[*it-'A'];
        }
    }

    for(auto it = words.begin(); it != words.end(); ++it){
        vector<int> t_charr_arr(char_arr);
        for( auto it0 = it->begin(); it0 != it->end(); ++it0)
        {
            if (*it0 >='a'&& *it0 <= 'z'){
                --t_charr_arr[*it0-'a'];
            }
            else if (*it0 >='A'&& *it0 <= 'Z'){
                --t_charr_arr[*it0-'A'];
            }
        }
        bool isOk = true;
        int words_cnt = 0;
        for(auto it1:t_charr_arr)
        {
            if(it1 >0){
                isOk = false;
                break;
            }
            words_cnt -= it1;

        }
        if(isOk == false)
            continue;
        else
            res.insert(pair<int, string>(words_cnt, *it));
    }
    
//    for (auto it = res.begin(); it != res.end(); ++it){
//        cout<<it->first<<'\t'<<it->second<<endl;
//    }
    return res.begin()->second;
}


int main(int argc, const char * argv[]) {
    vector<string> v{"step", "steps", "stripe", "stepple"};
    // insert code here...
    cout<<shortestCompletingWord("1s3 PSt", v);
//    std::cout << "Hello, World!\n";
    return 0;
}
