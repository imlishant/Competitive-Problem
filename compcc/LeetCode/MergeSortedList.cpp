#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode *head = new ListNode();
        ListNode *ans = head;
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                ans->next = new ListNode(p1->val);
                p1 = p1->next;
            } else {
                ans->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            ans = ans->next;
        }
        
        while (p1) {
            ans->next = new ListNode(p1->val);
            ans = ans->next;
            p1 = p1->next;
        }
        
        while (p2) {
            ans->next = new ListNode(p2->val);
            ans = ans->next;
            p2 = p2->next;
        }
        
        return head->next;
    }
};

*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode *ans = nullptr;

        if (list1->val < list2->val) {
            ans = list1;
            ans->next = mergeTwoLists(list1->next, list2);
        } else {
            ans = list2;
            ans->next = mergeTwoLists(list1, list2->next);
        }

        return ans;
    }
};