//
// Created by 橙子味 on 2025/1/2.
//
#include <iostream>
using namespace std;
// * Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* visit(ListNode* head, ListNode* &real_head) {
    if (head == nullptr) return nullptr;
    ListNode* front_p = visit(head->next,real_head);
    if (front_p == nullptr)  real_head = head;
    else {
        front_p->next = head;
    }
    return head;

}
ListNode* reverseList(ListNode* head) {
    ListNode* new_head = nullptr;
    visit(head,new_head);
    if (head != nullptr)
        head->next = nullptr;
    return new_head;
}
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    auto new_head = reverseList(head);
    cout<<new_head->val<<endl;
    cout<<new_head->next->val<<endl;
    cout<<new_head->next->next->val<<endl;
    cout<<new_head->next->next->next->val<<endl;
    cout<<new_head->next->next->next->next->val<<endl;
  }