//
// Created by 橙子味 on 2025/3/19.
//基于hash和两次遍历，改了2版才写对
#include <unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> hash;
    Node* new_head = new Node(1234);
    Node* cur = new_head, *old_cur = head;
    while(old_cur != nullptr){
        cur->next = new Node(old_cur->val);
        hash[old_cur] =  cur->next ;
        cur = cur->next;
        old_cur = old_cur->next;
    }
    cur = new_head->next;
    old_cur = head;
    while(cur != nullptr){
        cur->random = hash[old_cur->random];
        cur = cur->next;
        old_cur = old_cur->next;
    }
    return new_head->next;
}