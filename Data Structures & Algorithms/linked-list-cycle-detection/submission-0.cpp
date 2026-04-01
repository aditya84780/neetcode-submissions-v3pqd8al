/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == nullptr) return head;
        unordered_map<ListNode*, int> mp;
        ListNode* cur = head;
        while(cur -> next != nullptr && !mp[cur -> next]) {
            cur = cur->next;
            mp[cur] = 1;
        }
        return cur->next!=nullptr;
    }
};
