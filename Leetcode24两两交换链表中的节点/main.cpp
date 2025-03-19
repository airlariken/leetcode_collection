//
// Created by 橙子味 on 2025/3/18.
// 写的有点混乱，可以到时候重写一遍
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* left = head, *right = head->next;
    ListNode* realhead = head->next!= nullptr ? head->next : head;
    while(left!= nullptr && right != nullptr){
        ListNode * pre = left;
        // cout<<left->val<<'\t'<<right->val<<endl;
        left->next = right->next;
        right->next = left;
        //更新下一个l和r
        left = left->next;
        if(left != nullptr)
            right = left->next;
        else    right = nullptr;
        if (right != nullptr)
            pre->next = right;
    }
    return realhead;
}
