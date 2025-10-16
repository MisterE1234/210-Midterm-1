//COMSC-210|Midterm 1| Ethan Aylard
//IDE Used: Visual Studio Code
// This Project
#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
// Node structure for doubly linked list that contains an integer data field and pointers to the previous and next nodes.:
struct Node {
int data;
Node* prev;
Node* next;
Node(int val, Node* p = nullptr, Node* n = nullptr) {
data = val;
prev = p;
next = n;
}
};

Node* head;
Node* tail;

public:
//Default Constructor:
DoublyLinkedList() { head = nullptr; tail = nullptr; }

//insert_after(): Insters a new value after a specified position in the list.
//requires: and int for the value and an int for the position
void insert_after(int value, int position) {
// Making sure the position is not negative
if (position < 0) {
cout << "Position must be >= 0." << endl;
return;
}
// Create the new node and making sure the list is not empty
Node* newNode = new Node(value);
if (!head) {
head = tail = newNode;
return;
}
// Traverse to the specified position using a for loop and a temporary pointer
Node* temp = head;
for (int i = 0; i < position && temp; ++i)
temp = temp->next;
// If the position exceeds the list size, notify the user and delete the new node
if (!temp) {
cout << "Position exceeds list size. Node not inserted.\n";
delete newNode;
return;
}
// Insert the new node after the specified position by adjusting the pointers
newNode->next = temp->next;
newNode->prev = temp;
if (temp->next)
temp->next->prev = newNode;
else
tail = newNode;
temp->next = newNode;
}

// delete_val(): Deletes the first occurrence of a specified value from the list.
// requires: an int for the value to be deleted
void delete_val(int value) {
if (!head) return;
Node* temp = head;
// Traverse the list to find the node with the specified value using a while loop
while (temp && temp->data != value)
// Move to the next node and check if the end of the list is reached
temp = temp->next;
if (!temp) return;
// Adjust the pointers to remove the node from the list
if (temp->prev)
temp->prev->next = temp->next;
else
head = temp->next;
// Adjust the tail if the deleted node was the last node
if (temp->next)
temp->next->prev = temp->prev;
else
tail = temp->prev;
delete temp;
}
void delete_pos(int pos) {
if (!head) {
cout << "List is empty." << endl;
return;
}
if (pos == 1) {
pop_front();
return;
}
Node* temp = head;
for (int i = 1; i < pos; i++){
if (!temp) {
cout << "Position doesn't exist." << endl;
return;
}
else
temp = temp->next;
}
if (!temp) {
cout << "Position doesn't exist." << endl;
return;
}
if (!temp->next) {
pop_back();
return;
}
Node* tempPrev = temp->prev;
tempPrev->next = temp->next;
temp->next->prev = tempPrev;
delete temp;
}
void push_back(int v) {
Node* newNode = new Node(v);
if (!tail)
head = tail = newNode;
else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
}
void push_front(int v) {
Node* newNode = new Node(v);
if (!head)
head = tail = newNode;
else {
newNode->next = head;
head->prev = newNode;
head = newNode;
}
}
void pop_front() {
if (!head) {
cout << "List is empty." << endl;
return;
}
Node * temp = head;
if (head->next) {
head = head->next;
head->prev = nullptr;
}
else
head = tail = nullptr;
delete temp;
}
void pop_back() {
if (!tail) {
cout << "List is empty." << endl;
return;
}
Node * temp = tail;
if (tail->prev) {
tail = tail->prev;
tail->next = nullptr;
}
else
head = tail = nullptr;
delete temp;
}
~DoublyLinkedList() {
while (head) {
Node* temp = head;
head = head->next;
delete temp;
}
}
void print() {
Node* current = head;
if (!current) {
cout << "List is empty." << endl;
return;
}
while (current) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}
void print_reverse() {
Node* current = tail;
if (!current) {
cout << "List is empty." << endl;
return;
}
while (current) {
cout << current->data << " ";
current = current->prev;
}
cout << endl;
}
};
int main() {
cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid compiler warning
return 0;

}