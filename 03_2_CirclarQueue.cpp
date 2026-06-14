#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int arr[MAX];
    int front;
    int rear;
    int count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % MAX;
        arr[rear] = value;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int value = arr[front];
        front = (front + 1) % MAX;
        count--;

        return value;
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return arr[front];
    }

    int Rear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return arr[rear];
    }

    int size() {
        return count;
    }

    void clear() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX;
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.print();

    cout << "dequeue: " << q.dequeue() << endl;

    q.print();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    q.print();

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}