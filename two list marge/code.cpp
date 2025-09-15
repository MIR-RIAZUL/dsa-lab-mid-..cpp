#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node *mergeTwoLists(Node *head1, Node *head2)
{

    if (!head1)
        return head2;
    if (!head2)
        return head1;

    if (head1->data < head2->data)
    {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = mergeTwoLists(head1,head2->next);
        return head2;
    }
}

// Print function
void displayList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{

    Node *list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);
    list1->next->next->next = new Node(7);

    Node *list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "Two sorted singly linked lists:" << endl;
    displayList(list1);
    displayList(list2);


    Node *result = mergeTwoLists(list1, list2);

    cout << "\nAfter merging:" << endl;
    displayList(result);

    return 0;
}
