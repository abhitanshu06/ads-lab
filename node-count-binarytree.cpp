//write a program to count the number of nodes in a binary tree


#include <iostream>
using namespace std;

template <typename type>
class Tree
{
    struct Node
    {
        type data;
        Node *left;
        Node *right;

        Node(type d)
        {
            data = d;
            left = right = nullptr;
        }
    };

public:
    Node *ptr= nullptr;

    Tree()
    {
        Node *f = new Node('F');
        Node *b = new Node('B');
        Node *g = new Node('G');
        Node *a = new Node('A');
        Node *d = new Node('D');
        Node *i = new Node('I');
        Node *c = new Node('C');
        Node *e = new Node('E');
        Node *h = new Node('H');

        f->left = b;
        f->right = g;
        b->left = a;
        b->right = d;
        g->right = i;
        d->left = c;
        d->right = e;
        i->left = h;

        Root= f;
    }

    int countNodes(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    Tree<char> obj;
    if(obj.ptr != nullptr) {
        int count = obj.countNodes(obj.ptr);
        cout << "Number of nodes in the binary tree: " << count << endl;
    } else {
        cout << "The binary tree is empty." << endl;
    }
    return 0;
}