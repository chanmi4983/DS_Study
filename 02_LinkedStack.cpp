#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedStack {
private:
    Node* top;
    int count;

public:
    LinkedStack() {
        top = nullptr;
        count = 0;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = top;

        top = newNode;
        count++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        Node* temp = top;
        int value = temp->data;

        top = top->next;

        delete temp;
        count--;

        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->data;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* current = top;

        cout << "Stack: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.print();

    cout << "peek: " << s.peek() << endl;

    cout << "pop: " << s.pop() << endl;

    s.print();

    cout << "peek: " << s.peek() << endl;

    return 0;
}