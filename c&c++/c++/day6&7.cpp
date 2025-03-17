#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left, * right;

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertfunction(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (root->data > value) {
        root->left = insertfunction(root->left, value);
    } else if (root->data < value) {
        root->right = insertfunction(root->right, value);
    }

    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* bstSearch(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;
    }
    if (value > root->data) {
        return bstSearch(root->right, value);
    }
    return bstSearch(root->left, value);
}

// Move findparent() above deleteNode()
Node* findparent(Node* root, Node* child) {
    if (root == nullptr || root == child) {
        return nullptr;
    }
    if (root->right == child || root->left == child) {
        return root;
    }

    if (child->data > root->data) {
        return findparent(root->right, child);
    } else {
        return findparent(root->left, child);
    }
}

Node* deleteNode(Node* root, Node* loc, int value) {
    loc = bstSearch(root, value);
    if (loc == nullptr) {
        cout << "Value " << value << " not found in the tree." << endl;
        return root;
    }

    if (loc == root) {
        if (loc->right != nullptr && loc->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
            return root;
        } else if (loc->left != nullptr && loc->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
            return root;
        }
    }

    Node* parent = findparent(root, loc);

    if (loc->right != nullptr && loc->left == nullptr) {
        if (parent->right == loc) {
            parent->right = loc->right;
        } else {
            parent->left = loc->right;
        }
        delete loc;
    } else if (loc->left != nullptr && loc->right == nullptr) {
        if (parent->right == loc) {
            parent->right = loc->left;
        } else {
            parent->left = loc->left;
        }
        delete loc;
    }

    return root;
}

int main() {
    Node* root = nullptr;
    int k, l;
    cout << "Currently, the tree is empty." << endl;
    cout << "Enter the number of values to be inserted: ";
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> l;
        root = insertfunction(root, l);
    }

    // Traversal examples
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    // Deletion example
    cout << "Enter a value to delete: ";
    cin >> l;
    root = deleteNode(root, root, l);
    
    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
