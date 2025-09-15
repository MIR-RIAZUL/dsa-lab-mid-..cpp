#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};
node *head = NULL;

node *createNode(int val)
{
    node *newnode = new node();
    newnode->next = NULL;
    newnode->val = val;

    return newnode;
}

void insertHead(int val)
{
    node *newnode = createNode(val);
    newnode->next = head;
    head = newnode;
}

void insertLast(int val)
{
    node *newnode = createNode(val);
    if (head == NULL)
    {
        insertHead(val);
    }
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertPosition(int val, int n)
{
    node *newnode = createNode(val);
    if (head == NULL)
    {
        insertHead(val);
    }
    node *temp = head;
    for (int i = 0; i < n; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteHead()
{
    if (head == NULL)
    {
        cout << "the list is empty" << endl;
    }
    node *temp = head;
    head = temp->next;
    delete (temp);
}
void deleteLAST()
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    delete (temp->next);
}

void deletNth(int pos)
{
    node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void reverseList()
{
    node *pre = NULL;
    node *current = head;
    node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    head = pre;
}
node *findMiddle()
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printlist()
{
    node *temp = head;
    if (head == NULL)
    {
        cout << "the list id empty" << endl;
    }
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void menu()
{
    cout << "1.insert at head" << endl;
    cout << "2.insert at tail" << endl;
    cout << "3.insert at position" << endl;
    cout << "4.delete head" << endl;
    cout << "5.delete last" << endl;
    cout << "6.delete pos" << endl;
    cout << "7.reverse list" << endl;
    cout << "8.find mid" << endl;

    cout << "10. print list" << endl;
    cout << "enter your choice:";
}

int main()
{
    int choice;

    while (1)
    {
        menu();
        cin >> choice;

        if (choice == 1)
        {
            cout << "enter the value:";
            int val;
            cin >> val;
            insertHead(val);
        }
        else if (choice == 2)
        {
            cout << "enter the value:";
            int val;
            cin >> val;
            insertLast(val);
        }
        else if (choice == 3)
        {
            cout << "enter the value:";
            int val;
            cin >> val;
            cout << "enter position:";
            int n;
            cin >> n;
            insertPosition(val, n);
        }
        else if (choice == 4)
        {
            deleteHead();
        }
        else if (choice == 5)
        {
            deleteLAST();
        }
        else if (choice == 6)
        {
            cout << "enter the position you want to delete:" << endl;
            int pos;
            cin >> pos;
            deletNth(pos);
        }
        else if (choice == 7)
        {
            reverseList();
        }
        else if (choice == 8)
        {
            findMiddle();
        }

        else if (choice == 10)
        {
            printlist();
        }
    }

    return 0;
}