//
// Created by 橙子味 on 2025/1/2.
//
#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *detectCycle(ListNode *head) {
    ListNode* begin = head;
    unordered_set<ListNode*> unord_set;
    ListNode *start_cycle_pos_p = nullptr;
    while (head) {
        if (unord_set.find(head) == unord_set.end())
            unord_set.insert(head);
        else{
            start_cycle_pos_p = head;
            break;
        }

        head = head->next;
    }
    if (head == nullptr) return nullptr;
    while (begin) {
        if (begin == start_cycle_pos_p)
            return begin;
        begin = begin->next;
    }
    return nullptr;
}

//看完题解改进版本
ListNode *detectCycle1(ListNode *head) {
    ListNode* begin = head;
    unordered_set<ListNode*> unord_set;
    while (head) {
        if (unord_set.find(head) == unord_set.end())
            unord_set.insert(head);
        else
            break;
        head = head->next;
    }
    return head;
}
int main()
{

}