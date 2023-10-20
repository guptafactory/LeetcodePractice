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
    // Divide & conquer
    ListNode* mergeKlist1(vector<ListNode*>& lists, int start, int end) {
        if(start > end) return NULL;
        if(start == end) return lists[start];
        int mid = start + (end - start)/2;
        
        ListNode* l1 = mergeKlist1(lists, start, mid);
        ListNode* l2 = mergeKlist1(lists, mid+1, end);
        
        return mergeTwoLists(l1, l2);
    }
    // Priority Queue
    
    ListNode* mergeKlist2(vector<ListNode*> &lists) {
        auto comp = [](ListNode* a, ListNode* b) { return (a->val) > (b->val); };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        ListNode* dummy = new ListNode(-1e5), *prev = dummy;
        for(auto node: lists) {
            if(node != NULL) pq.push(node);
        }
        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            prev->next = node;
            prev = prev->next;
            node = node->next;
            if(node != NULL) pq.push(node);
        }
        return dummy->next;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        // return mergeKlist1(lists, 0, lists.size() - 1);
        return mergeKlist2(lists);
    }
};