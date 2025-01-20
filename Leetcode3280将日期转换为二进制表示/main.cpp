//
// Created by 橙子味 on 2025/1/1.
//
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string toBinary(int date) {
    string res = "";
    while(date != 0){
        char t = date%2 + '0';
        // cout<<t<<'\t';
        res += t;
        date /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

string convertDateToBinary(string date) {
    string res;
    int years=0, months=0, days=0;

    years = std::stoi(date.substr(0,4));
    cout<<toBinary(years)<<endl;


    months = std::stoi(date.substr(5,7));
    days = std::stoi(date.substr(8,10));
    res+=toBinary(years)+'-'+toBinary(months)+"-"+toBinary(days);
    return res;
}
int main() {
   cout<<convertDateToBinary("1900-01-01")<<endl;
}