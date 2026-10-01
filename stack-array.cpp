#include <iostream>
using namespace std;

int stack[100], top = -1;

void push(int value) {
    if (top == 99) {
        cout << "Stack overflow!" << endl;
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        cout << "Stack underflow!" << endl;
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return stack[top];
}

void display() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    cout << "Popped value: " << value << endl;
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    cout << "Top value: " << value << endl;
                }
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
    return 0;
}