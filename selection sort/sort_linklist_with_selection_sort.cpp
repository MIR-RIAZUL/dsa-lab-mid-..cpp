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

void selection_sort(node* head)
{
    for(node* i=head;i!=NULL;i=i->next)
    {
        node* smallest=i;
       for(node* j=i->next;j !=NULL;j=j->next)
       {
        if(j->val<smallest->val)
        {
            smallest=j;
        }
       }
       int temp= i->val;
       i->val=smallest->val;
       smallest->val=temp;
    }
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
    list1->next = new node(9);
    list1->next->next = new node(3);
    list1->next->next->next = new node(7);
    list1->next->next->next->next = new node(4);

;
    printlist(list1);

    selection_sort(list1);
    printlist(list1);



    return 0;
}
