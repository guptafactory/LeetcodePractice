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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;
        ListNode* curr = head;
        vector<int> smaller;
        vector<int> greater;
        while (curr != NULL) {
            if (curr->val < x) smaller.push_back(curr->val);
            else greater.push_back(curr->val);
            curr = curr->next;
        }
        int n = smaller.size(), m = greater.size(), i = 0, j = 0;
        ListNode* new_head = new ListNode(0);
        curr = new_head;
        while (i < n) {
            curr->next = new ListNode(smaller[i++]);
            curr = curr->next;
        }
        while (j < m) {
            curr->next = new ListNode(greater[j++]);
            curr = curr->next;
        }
        return new_head->next;
    }
};