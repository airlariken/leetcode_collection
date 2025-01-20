//
// Created by 橙子味 on 2025/1/2.
//
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
bool hasCycle(ListNode *head) {
    if (head == NULL) return false;
    ListNode *slow_p = head;
    ListNode *fast_p = head->next;
    while(fast_p != NULL && fast_p->next != NULL){
        if (fast_p == slow_p)
            return true;
        fast_p = fast_p->next->next;
        slow_p = slow_p->next;
    }
    return false;
}
int main()
{

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = head;
    cout<<hasCycle(head);
}

