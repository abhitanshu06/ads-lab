#include<bits/stdc++.h>
using namespace std;
#define size 100
class Queue{
    int front,rear;
    int arr[size];
    public:
    Queue(){
        front=-1;
        rear=-1;
    }
    void enqueue(int x){
        if(rear==size-1){
            cout<<"Queue is full"<<endl;
            return;
        }
        if(front==-1){
            front=0;
        }
        rear++;
        arr[rear]=x;
    }
    void dequeue(){
        if(front==-1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Dequeued element is: "<<arr[front]<<endl;
        front++;
    }
    void peek(){
        if(front==-1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Front element is: "<<arr[front]<<endl;
    }
    void display(){
        if(front==-1|| front>rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.peek();
    q.dequeue();
    q.display();
    return 0;
}