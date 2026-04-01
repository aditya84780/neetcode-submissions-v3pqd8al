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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Node* head = list1;
        // if(list1->val > list2->val) head = list2;
        // Node* nxt1 = list1, nxt2 = list2;
        // if(nxt1 -> val > nxt2 -> val) {
        //     Node* temp1 = nxt1 -> next;
        //     Node* temp2 = nxt2 -> next;
        //     nxt2 -> next = nxt1;
        //     nxt2 = temp2;
        // }
        ListNode* cur = list1, *head = list1;
        ListNode* nxt1 = list1, *nxt2 = list2;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        if(list1->val > list2 -> val) {
            head = list2;
            cur = list2;
            nxt2 = cur -> next;
        } else {
            head = list1;
            cur = list1;
            nxt1 = cur->next;
        }
        while(cur->next != nullptr) {
            if(nxt1->val > nxt2->val) {
                cur -> next = nxt2;
                cur = nxt2;
                nxt2 = nxt2 -> next;
            } else {
                cur -> next = nxt1;
                cur = nxt1;
                nxt1 = nxt1 -> next;
            }
        }
        if(nxt1 == nullptr) {
            cur->next = nxt2;
        } else if(nxt2 == nullptr) {
            cur->next = nxt1;
        }
        return head;
    }
};
