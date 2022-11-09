#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> vis;
        ListNode *curr = head;
        
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        while (curr) {
            if (vis[curr] == true) return true;
            vis[curr] = true;
            curr = curr->next;
        }
        
        return false;
    }
};