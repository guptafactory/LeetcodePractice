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
        int flag = 0;
        ListNode* newHead = new ListNode(0); // dummy
        ListNode* curr = newHead;
        while(list1 != NULL && list2 != NULL) {
            flag = (list1->val <= list2->val ? 1 : 0);
            if(flag) { curr->next = list1; list1 = list1->next; }
            else { curr->next = list2; list2 = list2->next; }
            curr = curr->next;
        }
        if(list1 != NULL) curr->next = list1;
        if(list2 != NULL) curr->next = list2;
        return newHead->next;
    }
};