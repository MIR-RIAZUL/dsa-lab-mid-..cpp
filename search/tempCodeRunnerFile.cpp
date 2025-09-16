#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(0) {} // 
};


void pushBack(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) 
        temp = temp->next;
    temp->next = newNode;
}


void printList(Node* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "END" << endl;
}


Node* search(Node* head, int target) {
    while (head) { 
        if (head->val == target)
            return head;
        else if (head->val > target)
            return 0; 
        head = head->next;
    }
    return 0; 
}

int main() {
    Node* head = 0; 

    pushBack(head, 1);
    pushBack(head, 3);
    pushBack(head, 5);
    pushBack(head, 7);
    pushBack(head, 9);

    cout << "Linked list: ";
    printList(head);

    int target;
    cout << "Enter number to search: ";
    cin >> target;

    Node* result = search(head, target);
    if (result)
        cout << "Found " << target << " in the list." << endl;
    else
        cout << target << " not found in the list." << endl;

    return 0;
}
