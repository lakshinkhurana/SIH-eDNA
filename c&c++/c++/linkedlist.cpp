#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    if (!newNode) {
        cout << "Memory allocation failed." << endl;
        exit(1);
    }
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void printList(Node* node) {
    while (node) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "null" << endl;
}

int lowestValue(Node* node) {
    if (node == nullptr) {
        cout << "The list is empty." << endl;
        return -1; 
    }

    int lowest = node->data;

    while (node != nullptr) {
        if (node->data < lowest) {
            lowest = node->data;
        }
        node = node->next;
    }

    return lowest;
}

bool traverseList(Node*node,int toFind){
    while(node){
        if(node->data==toFind){
            cout<<"Found at "<<node<<endl;
            return true;
        }
        node=node->next;
    }
}

void deleteFromList(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->data == value) {
        Node* temp = head;  
        head = head->next;  
        delete temp;        
        return;             
    }

    Node* current = head->next;  
    Node* prev = head;

    while (current != nullptr) {
        if (current->data == value) {
            prev->next = current->next; 
            delete current;              
            return;                     
        }
        prev = current;                 
        current = current->next;        
    }

    cout << "Node with value " << value << " not found." << endl; 
}

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;

}

void insertAtPosition(Node*& head, int value, int position) {
    Node* newNode = createNode(value); 

    if (position == 0) {
        insertAtBeginning(head, value);
        return;
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < position - 1; ++i) { 
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position is out of bounds." << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode';  
}





int main() {
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(-1);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    printList(node1);

    cout << "Lowest value: " << lowestValue(node1) << endl;

    traverseList(node1,3);

    deleteFromList(node1,3);

    printList(node1);

    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
