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

// Function to find intersection
void intersection(node *head1, node *head2) {
    node *current = head1;

    cout << "Intersection values: ";
    while (current) {
        node *runner = head2;
        while (runner) {
            if (runner->val == current->val) {
                cout << current->val << " ";
                break; // found, move to next current
            }
            runner = runner->next;
        }
        current = current->next;
    }
    cout << endl;
}

// Print list
void printlist(node *head) {
    node *temp = head;
    if (!head) {
        cout << "The list is empty" << endl;
        return;
    }
    while (temp) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    node *list1 = new node(1);
    list1->next = new node(2);
    list1->next->next = new node(3);
    list1->next->next->next = new node(4);
    list1->next->next->next->next = new node(6);


    node *list2 = new node(3);
    list2->next = new node(4);
    list2->next->next = new node(5);
    list2->next->next->next = new node(6);

    cout << "List1: ";
    printlist(list1);
    cout << "List2: ";
    printlist(list2);

    intersection(list1, list2);

    return 0;
}
