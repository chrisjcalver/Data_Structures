// Collection of nodes where each node contains a data field and a reference to next node

// Advantages: Size is not fixed, Insertion and deletion are cheap

// Disadvantages: Random access not allowed, have to access sequentially from start
// requires extra memory for the reference, reverse traversing not possible in original form, searching is costly O(n) time, sorting is costly)


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

// This function prints contents of linked list
// starting from the given node
void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = NULL;

    // Function call
    printList(head);

    return 0;
}
