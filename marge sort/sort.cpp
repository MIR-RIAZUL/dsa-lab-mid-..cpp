#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
    node(int x) {
        val = x;
        next = NULL;
    }
};


void printList(node* head) {
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void push(node*& head, int val) {
    node* newnode = new node(val);
    newnode->next = head;
    head = newnode;
}


void splitList(node* source, node** frontRef, node** backRef) {
    node* slow = source;
    node* fast = source->next;


    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;  
}

// Merge two sorted lists
node* mergeSorted(node* a, node* b) {
    if (!a) return b;
    if (!b) return a;

    node* result = NULL;
    if (a->val <= b->val) {
        result = a;
        result->next = mergeSorted(a->next, b);
    } else {
        result = b;
        result->next = mergeSorted(a, b->next);
    }
    return result;
}


void mergeSort(node** headRef) {
    node* head = *headRef;
    if (!head || !head->next) return;

    node* a;
    node* b;

 
    splitList(head, &a, &b);

   
    mergeSort(&a);
    mergeSort(&b);

  
    *headRef = mergeSorted(a, b);
}


int main() {
    node* head = NULL;

   
    push(head, 5);
    push(head, 20);
    push(head, 4);
    push(head, 3);
    push(head, 30);

    cout << "Original list: ";
    printList(head);

    mergeSort(&head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
