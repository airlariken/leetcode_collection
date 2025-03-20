//
// Created by 橙子味 on 2025/3/20.
// 写的依托狗屎，参考gpt后进行修改，将list中的节点重置位置不能用swap，因为指针swap只改变两根指针方向，不改变节点的位置
// 应该用erase+push_back/front 或者最好的一步到位就是splice函数
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache {
    list<pair<int, int>> s;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (hash.find(key) != hash.end()){
            int value = hash[key]->second;
            s.splice(s.end(), s, hash[key]);        //将节点挪到end()之前
            return hash[key]->second;
        }
        return -1;
    }

    void put(int key, int value) {
        if(hash.find(key) != hash.end()){
            hash[key]->second = value;
            s.splice(s.end(), s, hash[key]);
        }
        else{
            if (s.size() == cap){
                auto rm_ele = s.begin();
                hash.erase(rm_ele->first);
                s.erase(rm_ele);
            }
            s.push_back(make_pair(key,value));
            auto back = --s.end();
            hash[key] = back;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */