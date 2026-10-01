#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int i){
        data=i;
        next=nullptr;
    }
};

void push(Node* &top, int item){
    Node* temp=new Node(item);
    temp->next=top;
    top=temp;
    cout<<item<<"pushed into stack \n";
}

int pop(Node* &top){
    if(top==nullptr){
        cout<<"Underflow \n";
        return -1;
    }
    Node* temp=top;
    int item=temp->data;
    top=top->next;
    delete temp;
    cout<<item<<"Pop from Stack \n";
    return item;
}

int peek(Node* top){
    if(top==nullptr){
        cout<<"Stack in empty \n";
        return -1;
    }
    return top->data;
}

void traverse(Node* top){
    cout<<"Stack: ";
    Node* temp=top;
    while(temp->next!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* top=nullptr;
    push(top,10);
    push(top,20);
    traverse(top);
    push(top,220);
    push(top,230);
    traverse(top);
    cout<<"Top element is "<<peek(top)<<endl;
    pop(top);
    traverse(top);
    pop(top);
    traverse(top);
    return 0;
}

