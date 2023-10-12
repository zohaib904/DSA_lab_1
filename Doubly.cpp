#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insertion at the end of the doubly linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Deletion of a node with a given value
    void remove(int value) {
        if (!head) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }

        cout << "Value not found in the list." <<endl;
    }

    // Display the doubly linked list from head to tail
    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" <<endl;
    }
};

int main() {
    DoublyLinkedList myList;

    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);

    cout << "Initial Doubly Linked List: ";
    myList.display();

    myList.remove(3); // Deleting node with value 3
    myList.remove(1); // Deleting node with value 1
    myList.remove(5); // Deleting a value not in the list

    cout << "Updated Doubly Linked List: ";
    myList.display();

    return 0;
}

