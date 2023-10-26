//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
        struct Node *head = new Node(-1), *temp = head, *c1 = l1, *c2 = l2;
        int carry = 0, sum = 0;
        while(c1 != NULL || c2 != NULL || sum) 
        {
            if(c1 != NULL) { sum += c1->data; c1 = c1->next; }
            if(c2 != NULL) { sum += c2->data; c2 = c2->next; }
            temp->next = new Node(sum%10);
            sum /= 10;
            temp = temp->next;
        }
        return (head->next);
    }
    struct Node* reverse(struct Node* head) {
        if(head == NULL || head->next == NULL) return head;
        struct Node *curr = head, *fwd = NULL, *prev = NULL;
        while(curr != NULL) {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if(first == NULL) return second;
        if(second == NULL) return first;
        
        struct Node* l1 = reverse(first);
        struct Node* l2 = reverse(second);
        struct Node* ans = addTwoNumbers(l1, l2);
    
        // first = reverse(l1);
        // second = reverse(l2);
        ans = reverse(ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends