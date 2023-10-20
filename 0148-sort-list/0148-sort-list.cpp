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
private:
    ListNode* middle(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeSortedList(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        bool flag;
        ListNode *dummy = new ListNode(-1e6), *curr = dummy;
        while(l1 != NULL && l2 != NULL) {
            flag = (l1->val <= l2->val) ? 1 : 0;
            if(flag) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1 != NULL) curr->next = l1;
        if(l2 != NULL) curr->next = l2;
        
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* mid = middle(head);
        ListNode* newHead = mid->next;
        mid->next = NULL;
        
        ListNode* s1 = sortList(head);
        ListNode* s2 = sortList(newHead);
        
        return mergeSortedList(s1, s2);
    }
};