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

ListNode* findMid(ListNode* head) {
    ListNode *sl = head, *ft = head->next;
    while(ft->next!=nullptr) {
        ft = ft->next;
        if(ft->next!=nullptr) {
            ft = ft->next;
            sl = sl->next;
        }
    }
    return sl;
}

void reverse(ListNode* node, ListNode** head) {
    if(node -> next == nullptr) {
        *head = node;
        return;
    }
    reverse(node->next, head);
    node -> next -> next = node;
    node -> next = nullptr;
}

void merge(ListNode* list1, ListNode* list2) {
    ListNode *nxt1 = list1, *nxt2 = list2;
    while(nxt1->next!=nullptr) {
        ListNode *temp1 = nxt1, *temp2 = nxt2;
        temp1 = nxt1->next;
        temp2 = nxt2->next;
        nxt1 -> next = nxt2;
        nxt2 -> next = temp1;
        nxt1 = temp1;
        nxt2 = temp2;
    }
    nxt1->next = nxt2;
}
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return;
        ListNode* mid = findMid(head);
        ListNode* list2 = mid->next;
        mid->next = nullptr;
        ListNode* reverseHead;
        reverse(list2, &reverseHead);
        merge(head, reverseHead);
    }
};
