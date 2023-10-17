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
        // returning 2nd middle element in case even nodes
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
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
    bool check(ListNode* head1, ListNode* head2) {
        while(head1 != NULL && head2 != NULL) {
            if(head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* newHead = mid->next;
        mid->next = NULL;
        newHead = reverseList(newHead);
        return check(head, newHead);
    }
};