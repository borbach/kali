#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data1, data2, data3;
    Node* prev;
    Node* next;
};

// Class for the doubly linked list
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to add a node to the end of the list
    void addNode(int d1, int d2, int d3) {
        Node* newNode = new Node;
        newNode->data1 = d1;
        newNode->data2 = d2;
        newNode->data3 = d3;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to delete a node with given data
    void deleteNode(int d1, int d2, int d3) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data1 == d1 && temp->data2 == d2 && temp->data3 == d3) {
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Node with given data not found" << endl;
    }

    // Function to find a node with given data
    void findNode(int d1, int d2, int d3) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data1 == d1 && temp->data2 == d2 && temp->data3 == d3) {
                cout << "Node found" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Node with given data not found" << endl;
    }

    // Function to display the list
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Data: " << temp->data1 << ", " << temp->data2 << ", " << temp->data3 << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DoublyLinkedList list;

    int choice, d1, d2, d3;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add a node" << endl;
        cout << "2. Delete a node" << endl;
        cout << "3. Find a node" << endl;
        cout << "4. Display the list" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter three data elements: ";
                cin >> d1 >> d2 >> d3;
                list.addNode(d1, d2, d3);
                break;

            case 2:
                cout << "Enter the data of the node to be deleted: ";
                cin >> d1 >> d2 >> d3;
                list.deleteNode(d1, d2, d3);
                break;

            case 3:
                cout << "Enter the data of the node to be found: ";
                cin >> d1 >> d2 >> d3;
                list.findNode(d1, d2, d3);
                break;

            case 4:
                list.displayList();
                break;

            case 5:
                cout << "Exiting the program" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}


