/*
QUESTION:- 
Construct the linked list from arr and return the head of the linked list.

Example 1:

Input:
n = 5
arr = [1,2,3,4,5]
Output:
1 2 3 4 5
Explanation: Linked list for the given array will be 1->2->3->4->5.*/

struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};


Node* LL(vector<int>& num) {
    if (num.size() == 0) return NULL;

    Node* head = new Node(num[0]);
    Node* temp = head;

    for (int i = 1; i < num.size(); i++) {
        Node* current = new Node(num[i]);
        temp->next = current;
        temp = current;
    }
    return head;
}
