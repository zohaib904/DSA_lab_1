#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insertion at the end of the linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Deletion of a node with a given value
    void remove(int value) {
        if (!head) {
            cout << "List is empty. Cannot delete." <<endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }

        cout << "Value not found in the list." <<endl;
    }

    // Display the linked list
    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << std::endl;
    }
};

int main() {
    LinkedList myList;

    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);

    cout << "Initial Linked List: ";
    myList.display();

    myList.remove(3); // Deleting node with value 3
    myList.remove(1); // Deleting node with value 1
    myList.remove(5); // Deleting a value not in the list

    cout << "Updated Linked List: ";
    myList.display();

    return 0;
}


