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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* nHead = head->next, *temp = NULL, *odd = head, *even = nHead;
        
        while(odd->next != NULL && even->next != NULL) {
            temp = even->next;
            even->next = even->next->next;
            odd->next = temp;
            even = even->next;
            odd = odd->next;
        }
        odd->next = nHead;
        return head;
    }
};