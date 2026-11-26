#include <iostream>
using namespace std;

template<typename type>
class Tree{
    struct Node{
        type data;
        Node* left, * right;
        Node(type data){
            this->data = data;
            left = right = nullptr;
        }
    };

    public:
    Node* Root;
    Tree(){
        Root=new Node('F');

        Root->left=new Node('B');
        Root->right=new Node('G');

        Root->left->left=new Node('A');
        Root->left->right=new Node('D');

        Root->left->right->left=new Node('C');
        Root->left->right->right=new Node('E');

        Root->right->right=new Node('I');
        Root->right->right->left=new Node('H');

    }

    void DFS(Node* ptr){
        if(ptr==nullptr) return;
        cout<<ptr->data<<" ";
        
        DFS(ptr->left);
        DFS(ptr->right);
    }

};

int main(){
    Tree<char> tree;
    tree.DFS(tree.Root);  
    return 0;
}