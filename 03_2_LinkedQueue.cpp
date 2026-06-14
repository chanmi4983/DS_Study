#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedQueue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    LinkedQueue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    ~LinkedQueue() {
        clear();
    }

    bool isEmpty() {
        return front == nullptr;
    }

    int size() {
        return count;
    }

    void enqueue(int value) {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = nullptr;

        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        Node* temp = front;
        int value = temp->data;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        count--;

        return value;
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return front->data;
    }

    int Rear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return rear->data;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = front;

        cout << "Queue: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void clear() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
        count = 0;
    }
};

int main() {
    LinkedQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.print();

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;
    cout << "Size: " << q.size() << endl;

    cout << "Dequeue: " << q.dequeue() << endl;

    q.print();

    q.enqueue(40);
    q.enqueue(50);

    q.print();

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;
    cout << "Size: " << q.size() << endl;

    q.clear();

    q.print();

    return 0;
}