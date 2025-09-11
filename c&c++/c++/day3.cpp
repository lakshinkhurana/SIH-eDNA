#include<iostream>
using namespace std;

// Creating a node structure for linked list
struct Node{
    int data;
    Node*next;
};

//Function to create a new node
Node*createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to print a linked list
Node*printList(Node*rootNode){
    while(rootNode){
        cout<<rootNode->data<<" ";
        rootNode=rootNode->next;
    }
    cout<<"null";
}

//Function to find the lowest value
int lowestValue(Node*rootNode){
    int lowest;
    if(rootNode==nullptr){
        cout<<"The list is empty"<<endl;
        return -1;

    lowest=rootNode->data;

    }
    while(rootNode->next!=nullptr){
        if(rootNode->next->data<lowest){
            lowest=rootNode->next->data;
        }
        rootNode=rootNode->next;
    }
    return lowest;
}

//Function to find the element in linked list
Node*findNode(int data,Node*rootNode){
    if(rootNode->data==data){
        return rootNode;
    }else{
        findNode(data,rootNode->next);
    }
}

//Function to insert an element into a linked list
Node*insertintoNode(int data,Node*& rootNode,int position){
        Node*newNode=createNode(data);

    if(position==0){
        newNode->next=rootNode;
        rootNode=newNode;
        return rootNode;
    }
    Node*current=rootNode;
    for(int i =0;i<position-1 && current!=nullptr;i++){
        current=current->next;
    }
    if(current==nullptr){
        cout<<"Position is out of bounds"<<endl;
        delete newNode;
        return nullptr;
    }
    newNode->next=current->next;
    current->next=newNode;
    cout<<"Inserted";
    return rootNode;
}

//Function to delete a node from a linked list
Node* deleteNode(int data,Node*&rootnode){
    if(rootnode==nullptr){
        cout<<"List is empty"<<endl;
        return nullptr;
    }
    if(rootnode->data==data){
        Node*temp=rootnode;
        rootnode=rootnode->next;    
        delete temp;
        return rootnode ;
    }
    Node*current=rootnode->next;
    Node*prev=rootnode;

    while(current->next!=nullptr && current->data!=data && current!=nullptr){
        prev=current;
        current=current->next;
    }

    if(current==nullptr){
        cout<<"Node not found."<<endl;
        return rootnode;
    }
    prev->next=current->next;
    delete current;
    return rootnode;
}

//Function to delete an element from a linked list

int main(){
    //Creating Nodes
    Node*node1=createNode(1);
    Node*node2=createNode(9);
    Node*node3=createNode(11);
    Node*node4=createNode(7);
    Node*node5=createNode(4);

    //Linking Nodes
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;

    printList(node1);
    lowestValue(node1);
    findNode(11,node1);
    insertintoNode(4,node1,3);
    printList(node1);
    deleteNode(11,node1);
    printList(node1);

    return 0;
}