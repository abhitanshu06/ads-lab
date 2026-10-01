#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    public:
    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void insert(Node *&root, int value) {
    if (root == nullptr) {
        root = new Node(value);
    }
    else if (value < root->data) {
        insert(root->left, value);
    } 
    else {
        insert(root->right, value);
    }
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(root, value);
    }

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}