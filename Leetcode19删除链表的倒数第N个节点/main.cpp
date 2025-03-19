//
// Created by 橙子味 on 2025/3/18.
// 本次用双指针解，也可以用递归或者栈
struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fake_node = new ListNode(-1, head);
    ListNode* slow_n_p = fake_node;
    ListNode* cur = fake_node;
    for(int i = 0; i < n+1; ++i){
        cur = cur->next;
    }
    while(cur != nullptr){
        cur = cur->next;
        slow_n_p = slow_n_p->next;
    }
    if (slow_n_p->next != nullptr)
        slow_n_p->next = slow_n_p->next->next;
    return fake_node->next;
}