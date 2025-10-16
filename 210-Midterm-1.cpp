//COMSC-210|Midterm 1| Ethan Aylard
//IDE Used: Visual Studio Code
// This Project is the midterm exam for COMSC-210. I must comment all my code and create a new class method.

#include <iostream> //Insterting the iostream library to allow for input and output to the console
using namespace std; //Using the standard namespace to avoid having to type "std::" in front of everything.

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;// Declaring constant integers for easy modification later if needed.

class DoublyLinkedList { //Creating a class, DoublyLinkedList, to represent a doubly linked list data structure.
private: //Private access specifier to make it where only the class methods can access these members.

struct Node {// Node structure for doubly linked list that contains an integer data field and pointers to the previous and next nodes.:
int data; //declaring an integer variable to hold the data of the node
Node* prev; //Pointer to the previous node in the list
Node* next; //Pointer to the next node in the list

Node(int val, Node* p = nullptr, Node* n = nullptr) { //Constructor to initialize a node with an integer value, previous pointer, and next pointer.
data = val; // Set the data field to the provided value
prev = p; // Set the previous pointer to the provided previous node
next = n; // Set the next pointer to the provided next node
}
};

Node* head; //Pointer to the head (first node) of the list
Node* tail; //Pointer to the tail (last node) of the list

public: //Public access specifier to make it these member are able to be accessed outside the class.

DoublyLinkedList() { head = nullptr; tail = nullptr; } //Default Constructor: Initializes an empty list by setting head and tail to nullptr.

//insert_after(): Insters a new value after a specified position in the list.
//requires: and int for the value and an int for the position
void insert_after(int value, int position) {
// Making sure the position is not negative
if (position < 0) { // Position must be 0 or greater
cout << "Position must be >= 0." << endl; //Output an error message if the position is negative
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
// Delete the node to free memory
delete temp;
}

// delete_pos(): Deletes the node at a specified position in the list.
// requires: an int for the position to be deleted
void delete_pos(int pos) {
// Making sure the position is valid and the list is not empty
if (!head) {
cout << "List is empty." << endl;
return;
}
// Position must be 1 or greater
if (pos == 1) {
pop_front();
return;
}
// Traverse to the specified position using a for loop and a temporary pointer
Node* temp = head;
for (int i = 1; i < pos; i++){
// Checking if the position exists in the list
if (!temp) {
cout << "Position doesn't exist." << endl;
return;
}
// Move to the next node
else
temp = temp->next;
}
// If the new temp is null, it means we are at the end of the list
if (!temp) {
cout << "Position doesn't exist." << endl;
return;
}
// If the node to be deleted is the last node, call pop_back()
if (!temp->next) {
pop_back();
return;
}
// Adjust the pointers to remove the node from the list
Node* tempPrev = temp->prev;
tempPrev->next = temp->next;
temp->next->prev = tempPrev;
// Delete the node to free memory
delete temp;
}
//push_back(): Adds a new value to the end of the list.
//requires: an int for the value to be added
void push_back(int v) {
// Create the new node and making sure the list is not empty
Node* newNode = new Node(v);
if (!tail)
head = tail = newNode;
// If the list is not empty, adjust the pointers to add the new node at the end
else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
}

//push_front(): Adds a new value to the front of the list.
//requires: an int for the value to be added
void push_front(int v) {
// Create the new node and making sure the list is not empty
Node* newNode = new Node(v);
if (!head)
head = tail = newNode;
// If the list is not empty, adjust the pointers to add the new node at the front
else {
newNode->next = head;
head->prev = newNode;
head = newNode;
}
}
//pop_front(): Removes the first node from the list.
//requires: nothing
void pop_front() {
// Making sure the list is not empty
if (!head) {
cout << "List is empty." << endl;
return;
}
// Store the old head in a temporary pointer
Node * temp = head;
if (head->next) {
head = head->next;
head->prev = nullptr;
}
// If there was only one node, set head and tail to nullptr
else
head = tail = nullptr;
// Delete the old head to free memory
delete temp;
}
//pop_back(): Removes the last node from the list.
//requires: nothing
void pop_back() {
// Making sure the list is not empty
if (!tail) {
cout << "List is empty." << endl;
return;
}
// Store the old tail in a temporary pointer
Node * temp = tail;
if (tail->prev) {
tail = tail->prev;
tail->next = nullptr;
}
// If there was only one node, set head and tail to nullptr
else
head = tail = nullptr;
// Delete the old tail to free memory
delete temp;
}

// Destructor to free memory when the list is no longer needed
//requires: nothing
~DoublyLinkedList() {
// Traverse the list and delete each node
while (head) {
Node* temp = head;
head = head->next;
//delete the node to free memory
delete temp;
}
}

//print(): Prints the list from head to tail.
//requires: nothing
void print() {
// Making sure the list is not empty
Node* current = head;
if (!current) {
cout << "List is empty." << endl;
return;
}
// Traverse the list and print each node's data
while (current) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}

//print_reverse(): Prints the list from tail to head.
//requires: nothing
void print_reverse() {
// Making sure the list is not empty
Node* current = tail;
if (!current) {
cout << "List is empty." << endl;
return;
}
// Traverse the list in reverse and print each node's data
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