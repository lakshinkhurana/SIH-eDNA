#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert into hash table using chaining
void insert(int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Search for a key in the hash table
struct Node* search(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Delete a key from the hash table
void deleteKey(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key %d not found in hash table.\n", key);
        return;
    }

    if (prev == NULL) {
        hashTable[index] = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Key %d deleted from hash table.\n", key);
}

// Display the hash table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert keys into the hash table
    insert(10);
    insert(20);
    insert(30);
    insert(42);
    insert(15);
    insert(28);

    // Display the hash table
    printf("Hash table:\n");
    display();

    // Search for a key in the hash table
    int key = 20;
    struct Node* result = search(key);
    if (result != NULL) {
        printf("Key %d found in hash table.\n", key);
    } else {
        printf("Key %d not found in hash table.\n", key);
    }

    // Delete a key from the hash table
    deleteKey(42);
    printf("Hash table after deletion:\n");
    display();

    return 0;
}
