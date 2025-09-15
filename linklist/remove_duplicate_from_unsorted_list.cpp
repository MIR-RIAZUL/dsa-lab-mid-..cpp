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
    for (int i = 1; i < n; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void removeDuplicates() {
    node* current = head;

    while (current) {
        node* runner = current;
        while (runner->next) {
            if (runner->next->val == current->val) {
                // Duplicate found, remove it
                node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
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
    cout<<"4.remove duplicate"<<endl;

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
            cout << "enter the value";
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
        else if (choice==4)
        {
            removeDuplicates();
        }
        

        else if (choice == 10)
        {
            printlist();
        }
    }

    return 0;
}