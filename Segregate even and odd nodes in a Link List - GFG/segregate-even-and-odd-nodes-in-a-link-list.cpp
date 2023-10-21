//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        if(head == NULL || head->next == NULL) return head;
        Node* curr = head, *temp = NULL, *head_odd = new Node(0), *odd = head_odd, *head_even = new Node(0), *even = head_even;
        while(curr != NULL) {
            if((curr->data) % 2) { odd->next = curr; odd = odd->next; }
            else { even->next = curr; even = even->next; }
            curr = curr->next;
        }
        odd->next = NULL;
        head_odd = head_odd->next;
        even->next = head_odd;
        if(head_even->next == NULL) head_even = head_odd;
        else head_even = head_even->next;
        
        
        return head_even;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends