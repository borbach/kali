#include <iostream>
#include <string>

using namespace std;
bool debug = false;
bool output = false

// Node structure for the doubly linked list
struct Node {
    string data;
    Node* prev;
    Node* next;
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr) {}

    // Function to add a node at the end of the list
    void addNode(string value) {
        Node* newNode = new Node;
        newNode->data = value;
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
	if( debug )
        	cout << "Node with value " << value << " added to the end of the list." << endl;
    }

    // Function to delete a node by name
    void deleteNodeByName(string name) {
	    Node *temp = findNodeByName( name );
	    if( temp ){
		    delete temp;
		    if( debug )
        		cout << "Node with name " << name << " deleted from the list." << endl;
	    }
	    else{
		    output = true
		    cout << "Node with name " << name << "not found in list. " << endl;
	    }
    }

    // Function to delete a node by id 
    void deleteNodeById(string id) {
	    Node *temp = findNodeById( id );
	    if( temp ){
		    delete temp;
		    if( debug )
        		cout << "Node with id " << id << " deleted from the list." << endl;
	    }
	    else{
		    output = true;
		    cout << "Node with id " << id << "not found in list. " << endl;
	    }
    }
    // Function to find a node by name 
    Node *findNodeByName(string name) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != name) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with name " << name << " not found in the list." << endl;
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
	return( temp );
    }

    // Function to find a node by id 
    Node *findNodeById(string id) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from an empty list." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != id) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with id " << id << " not found in the list." << endl;
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
	return( temp );
    }

    // Function to display the contents of the list
    void displayList() {
        cout << "Doubly Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    int choice;
    string value;

    do {
	choice = 0;
        cout << "\nMenu:\n";
        cout << "1. Add Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
	if( debug )
		cout << "Your choice is " << choice << endl;

        switch (choice) {
            case 1:
                cout << "Enter the value to add: ";
                cin >> value;
                list.addNode(value);
                break;

            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;

            case 3:
                list.displayList();
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}



