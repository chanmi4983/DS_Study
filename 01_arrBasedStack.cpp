//베열기반 

#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full" << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        int value = arr[top];
        top--;

        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return arr[top];
    }

    void clear() {
        top = -1;
    }

    int size() {
        return top + 1;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.print();

    cout << "Top value: " << s.peek() << endl;
    cout << "Size: " << s.size() << endl;

    cout << "Pop: " << s.pop() << endl;

    s.print();

    s.clear();

    s.print();

    return 0;
}