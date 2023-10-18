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
    ListNode* middleNode(ListNode* head) {
        // returning 1st middle element in case even nodes
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *curr = head, *prev = NULL, *fwd = NULL;
        while(curr != NULL) {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        int flag = 0;
        ListNode* newHead = new ListNode(0); // dummy
        ListNode* curr = newHead;
        while(list1 != NULL && list2 != NULL) {
            flag ^= 1;
            if(flag) { curr->next = list1; list1 = list1->next; }
            else { curr->next = list2; list2 = list2->next; }
            curr = curr->next;
        }
        if(list1 != NULL) curr->next = list1;
        if(list2 != NULL) curr->next = list2;
        return newHead->next;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* newHead = mid->next;
        mid->next = NULL;
        newHead = reverseList(newHead);
        head = mergeTwoLists(head, newHead);
        
    }
};