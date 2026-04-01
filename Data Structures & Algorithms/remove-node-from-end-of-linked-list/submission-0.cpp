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
    ListNode* removeNthFromEnd(ListNode* head, int N) {
        int n = 1;
    ListNode* last = head;
    while(last -> next != nullptr) {
        n++;
        last = last->next;
    }
    int indexFromStart = n-N;
    if(indexFromStart == 0) {
        head = head->next;
        return head;
    }
    ListNode* nodeFromStart = head;
    for(int i = 1; i<indexFromStart; i++) {
        nodeFromStart = nodeFromStart -> next;
    }
    nodeFromStart -> next = nodeFromStart->next->next;
    return head;
    }
};
