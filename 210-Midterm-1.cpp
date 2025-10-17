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

Node(int val, Node* p = nullptr, Node* n = nullptr) { //Constructor to initialize a node with an integer value and optional previous and next pointers.
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
return; // Exit the function early
}
// Create the new node and making sure the list is not empty
Node* newNode = new Node(value); // Create the new node by using the Node constructor
if (!head) { //If the head is empty:
head = tail = newNode; // Set both head and tail to the new node
return; // Exit the function early
}
// Traverse to the specified position using a for loop and a temporary pointer
Node* temp = head; // Temporary pointer to traverse the list
for (int i = 0; i < position && temp; ++i) //For loop to move to the specified position while checking to see if the end of the list is reached
temp = temp->next; // Move to the next node
// If the position exceeds the list size, notify the user and delete the new node
if (!temp) { // If temp is null, the position is out of bounds
cout << "Position exceeds list size. Node not inserted.\n"; // Output an error message
delete newNode; // Delete the newly created node to free memory
return; // Exit the function early
}
// Insert the new node after the specified position by adjusting the pointers
newNode->next = temp->next; // Set the new node's next to temp's next
newNode->prev = temp; // Set the new node's prev to temp
if (temp->next) // If temp is not the last node
temp->next->prev = newNode; // Adjust the next node's prev to point to the new node
else // If temp is the last node
tail = newNode; // Update the tail to the new node
temp->next = newNode; // Set temp's next to the new node
}

// delete_val(): Deletes the first occurrence of a specified value from the list.
// requires: an int for the value to be deleted
void delete_val(int value) {
// Making sure the list is not empty
if (!head) return; // If the list is empty, there is nothing to delete so return early

Node* temp = head; // Temporary pointer to traverse the list
// Traverse the list to find the node with the specified value using a while loop
while (temp && temp->data != value) //A while loop to find the node with the specified value while checking to see if the end of the list is reached
// Move to the next node and check if the end of the list is reached
temp = temp->next; // Move to the next node
if (!temp) return; // If the value was not found, exit the function early
// Adjust the pointers to remove the node from the list
if (temp->prev) // If the node to be deleted is not the head
temp->prev->next = temp->next; // Adjust the previous node's next pointer to skip the deleted node
else // If the node to be deleted is the head
head = temp->next; // Update the head to the next node
// Adjust the tail if the deleted node was the last node
if (temp->next) // If the node to be deleted is not the tail
temp->next->prev = temp->prev; // Adjust the next node's prev pointer to skip the deleted node
else // If the node to be deleted is the tail
tail = temp->prev; // Update the tail to the previous node
// Delete the node to free memory
delete temp;
}

// delete_pos(): Deletes the node at a specified position in the list.
// requires: an int for the position to be deleted
void delete_pos(int pos) {
// Making sure the position is valid and the list is not empty
if (!head) { // If the list is empty, there is nothing to delete so return early
cout << "List is empty." << endl; // Output an error message
return; // Exit the function early
}
// Position must be 1 or greater
if (pos == 1) { // If the position is 1
pop_front(); // Call pop_front() to remove the first node
return; // Exit the function early
}
// Traverse to the specified position using a for loop and a temporary pointer
Node* temp = head; // Temporary pointer to traverse the list
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