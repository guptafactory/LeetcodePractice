/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        unordered_map<Node*, Node*> mp;
        Node *curr = head, *prev = NULL, *newHead = NULL, *temp = NULL;
        // Creating new linked list with val, next but without random pointer 
        while(curr != NULL) {
            temp = new Node(curr->val);
            mp[curr] = temp;
            
            if(newHead == NULL) {
                newHead = temp;
                prev = temp;
            } else {
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }
        // assigning random pointer by map
        curr = head; 
        temp = newHead;
        while(curr != NULL) {
            if(curr->random == NULL) temp->random = NULL;
            else temp->random = mp[curr->random];
            
            curr = curr->next;
            temp = temp->next;
        }
        return newHead;
    }
};