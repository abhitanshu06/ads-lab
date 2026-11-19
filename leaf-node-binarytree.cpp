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
    Node *Root = nullptr;

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

        Root = f;
    }

    int countLeafNodes(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
};

int main()
{
    Tree<char> obj;
    if (obj.Root == nullptr)
    {
        cout << "Tree is empty!" << endl;
    }
    else
    {
        int leafNodeCount = obj.countLeafNodes(obj.Root);
        cout << "Number of leaf nodes: " << leafNodeCount << endl;
    }
    return 0;
}
