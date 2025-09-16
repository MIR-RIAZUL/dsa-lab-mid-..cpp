 #include<iostream>
 using namespace std;
 // Node structure for the doubly linked list
 struct node
 {
 int data;
 node* next;
 node* prev; // Pointer to the previous node
 };
 // Function to add a node at the end of the list
 void addEnd(node *&head, node *&tail, int val){
    node *newNode = new node();
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
 }
 // Function to add a node at the beginning of the list
 void addBeginning(node *&head, node *&tail, int val){
    node *newNode = new node();
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
 }
 // Function to add a node at a specific position
 void addPos(node *&head, int val, int pos){
    if (pos <= 0) {
        cout << "Invalid position." << endl;
        return;
    }
    if (pos == 1) {
        node *newNode = new node();
        newNode->data = val;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }
    node *temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }
    node *newNode = new node();
    newNode->data = val;
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
 }
 // Function to delete the node from the beginning
 void deleteBeginning(node *&head, node *&tail){
    if (head == NULL) return;
    
    node* temp = head;
    head = head->next;
    
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL; // The list is now empty
    }
    delete temp;
 }
 // Function to delete the node from the end
 void deleteEnd(node *&head, node *&tail){
    if (tail == NULL) return;
    node* temp = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL; // The list is now empty
    }
    delete temp;
 }
 // Function to delete a node from a specific position
 void deletePos(node *&head, int pos){
    if (head == NULL || pos <= 0) return;
    if (pos == 1) {
        node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        return;
    }
    node* temp = head;
    for(int i = 1; i < pos && temp != NULL; i++){
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }
    temp->prev->next = temp->next;
    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
 }
 // Function to display the list
 void display(node *head){
    node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
 }
 int main (){
    node *head1 = NULL, *tail1 = NULL;
    int x;
    do {
        cout << "1. Add at the end\n2. Add at beginning\n3. Add at any position\n4. Delet"<<endl;
        cin >> x;
        if(x == 1){
            int val;
            cout << "Enter value: ";
            cin >> val;
            addEnd(head1, tail1, val);
        }
        else if(x == 2){
            int val;
            cout << "Enter value: ";
            cin >> val;
            addBeginning(head1, tail1, val);
        }
        else if(x == 3){
            int val, pos;
            cout << "Enter value: ";
            cin >> val;
            cout << "Enter position: ";
            cin >> pos;
            addPos(head1, val, pos);
        }
        else if(x == 4){
            deleteBeginning(head1, tail1);
        }
        else if(x == 5){
            deleteEnd(head1, tail1);
        }
        else if(x == 6){
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            deletePos(head1, pos);
        }
        else if(x == 10){
            display(head1);
        }
    } while(x != 0);
    
    return 0;
    }