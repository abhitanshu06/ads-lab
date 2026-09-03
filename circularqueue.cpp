#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front;
    int rear;
    int size;
public:
    CircularQueue(int n) {
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }
    void enqueue(int x) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        arr[rear] = x;
    }
    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }
    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;
    }
};
int main() {
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(60);
    q.display();
    return 0;
}