#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
    int arr[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void push(int value) {
        arr[size] = value;
        size++;
    }

    void pop() {
        if (size == 0) {
            cout << "Priority Queue is empty";
            return;
        }

        int maxIndex = 0;

        for (int i = 1; i < size; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        for (int i = maxIndex; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    int top() {
        int maxIndex = 0;

        for (int i = 1; i < size; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        return arr[maxIndex];
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty";
            return;
        }

        while (size > 0) {
            cout << top() << " ";
            pop();
        }
    }
};

int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    cout << "Highest Priority: " << pq.top() << endl;

    cout << "Priority Queue: ";
    pq.display();

    return 0;
}
