#include <iostream>
#include <queue>
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

    void BFS(Node* ptr){
        if(ptr==nullptr) return;

        queue<Node*> q;
        q.push(ptr);

        while(!q.empty()){
            ptr=q.front();
            q.pop();

            cout<<ptr->data<<" ";

            if(ptr->left!=nullptr)
                q.push(ptr->left);

            if(ptr->right!=nullptr)
                q.push(ptr->right);
        }
    }
};

int main(){
    Tree<char> tree;
    tree.BFS(tree.Root);
    return 0;
}