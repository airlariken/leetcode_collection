//
// Created by 橙子味 on 2025/1/2.
//
#include <algorithm>
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
void visit(ListNode* cur, vector<int>& res) {
    if (cur == nullptr) return;
    res.push_back(cur->val);
    visit(cur->next, res);

}
bool isPalindrome(ListNode* head) {
    vector<int> res;
    visit(head, res);
    for (int i = 0; i < res.size() / 2; i++) {
        if (res[i] != res[res.size() - i - 1]) return false;
    }
    return true;
    // vector<int> rev_res(res);
    // reverse(rev_res.begin(), rev_res.end());
    // return res == rev_res;
}
int main()
{

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);
    cout<<isPalindrome(head);
}
