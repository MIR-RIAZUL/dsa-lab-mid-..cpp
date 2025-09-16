#include<iostream>
using namespace std;

struct node
{
    int val;
    node* next;
};

node* head = NULL;

node* createNode(int val)
{
    node* newnode= new node();
    newnode->next = NULL;
    newnode->val = val;
    return newnode;
}

void insertHead(int x)
{
    node* newnode= createNode(x);
    newnode->next = head;
    head = newnode;
}

void insertLast(int x)
{
    node* newnode = createNode(x);
    if(head == NULL)
    {
        head = newnode;
        return;
    }
    node* temp= head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

// Find middle between start and end
node* getMiddle(node* start, node* end)
{
    if(start == NULL)
        return NULL;

    node* slow = start;
    node* fast = start;

    while(fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Binary search in sorted linked list
node* binarySearch(node* head, int target)
{
    node* start = head;
    node* end = NULL;

    while(start != end)
    {
        node* mid = getMiddle(start, end);
        if(mid == NULL)
            return NULL;

        if(mid->val == target)
            return mid;
        else if(mid->val < target)
            start = mid->next;
        else
            end = mid;
    }
    return NULL;
}

void printlist()
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void menu()
{
    cout<<"\n1. Insert at head"<<endl;
    cout<<"2. Insert at tail"<<endl;
    cout<<"3. Binary Search"<<endl;
    cout<<"10. Print list"<<endl;
    cout<<"Enter your choice: ";
}

int main()
{
    int choice;

    while(1)
    {
        menu();
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter the value: ";
            int val;
            cin >> val;
            insertHead(val);
        }
        else if(choice == 2)
        {
            cout << "Enter the value: ";
            int val;
            cin >> val;
            insertLast(val);
        }
        else if(choice == 3)
        {
            cout << "Enter value to search: ";
            int key;
            cin >> key;
            node* result = binarySearch(head, key);
            if(result)
                cout << "Value found: " << result->val << endl;
            else
                cout << "Value not found" << endl;
        }
        else if(choice == 10)
        {
            printlist();
        }
    }

    return 0;
}
