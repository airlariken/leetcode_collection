//
// Created by 橙子味 on 2025/3/19.
// 参考了答案的写法改了才对的，找机会重刷

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = l1, *cur = head;
    int carry = 0;
    while(cur != nullptr || l2 != nullptr){
        int add = l2 != nullptr ? l2->val : 0;
        cur->val = cur->val + add + carry;
        carry = cur->val / 10;
        cur->val %= 10;
        if (cur->next == nullptr && l2 != nullptr)    {cur->next = l2->next;    l2 = nullptr;}
        if (cur->next == nullptr && carry && l2 == nullptr) {cur->next = new ListNode(1); break;}
        if (cur != nullptr)
            cur = cur->next;
        if (l2 != nullptr)
            l2 = l2->next;
    }
    return head;
}