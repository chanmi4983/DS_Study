#include <iostream>
using namespace std;

typedef int elem;

//
// 배열 기반 원형 큐
//
class MyCircularQueue {
private:
    int front;
    int rear;
    int maxSize;
    int count;
    elem* list;

public:
    MyCircularQueue(int size = 10) {
        maxSize = size;
        list = new elem[maxSize];

        front = 0;
        rear = -1;
        count = 0;
    }

    ~MyCircularQueue() {
        delete[] list;
    }

    void initialize() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == maxSize;
    }

    int size() const {
        return count;
    }

    void enqueue(const elem& e) {
        if (isFull()) {
            cout << "Circular Queue is full" << endl;
            return;
        }

        rear = (rear + 1) % maxSize;
        list[rear] = e;
        count++;
    }

    elem dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue is empty" << endl;
            return -1;
        }

        elem value = list[front];
        front = (front + 1) % maxSize;
        count--;

        return value;
    }

    elem frontItem() const {
        if (isEmpty()) {
            cout << "Circular Queue is empty" << endl;
            return -1;
        }

        return list[front];
    }

    elem rearItem() const {
        if (isEmpty()) {
            cout << "Circular Queue is empty" << endl;
            return -1;
        }

        return list[rear];
    }

    void print() const {
        if (isEmpty()) {
            cout << "Circular Queue is empty" << endl;
            return;
        }

        cout << "Circular Queue: ";

        int index = front;

        for (int i = 0; i < count; i++) {
            cout << list[index] << " ";
            index = (index + 1) % maxSize;
        }

        cout << endl;
    }
};


// =========================
// 연결 리스트 기반 큐
// =========================
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class MyLLQueue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    MyLLQueue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    ~MyLLQueue() {
        clear();
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    int size() const {
        return count;
    }

    void enqueue(const int& value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
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
            cout << "Linked List Queue is empty" << endl;
            return -1;
        }

        Node* temp = front;
        int value = temp->data;

        front = front->next;

        delete temp;
        count--;

        if (front == nullptr) {
            rear = nullptr;
        }

        return value;
    }

    int frontItem() const {
        if (isEmpty()) {
            cout << "Linked List Queue is empty" << endl;
            return -1;
        }

        return front->data;
    }

    int rearItem() const {
        if (isEmpty()) {
            cout << "Linked List Queue is empty" << endl;
            return -1;
        }

        return rear->data;
    }

    void printAll() const {
        if (isEmpty()) {
            cout << "Linked List Queue is empty" << endl;
            return;
        }

        Node* current = front;

        cout << "Linked List Queue: ";

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};


// =========================
// main 함수
// =========================
int main() {
    cout << "===== Circular Queue Test =====" << endl;

    MyCircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);

    cq.print();

    cout << "Front: " << cq.frontItem() << endl;
    cout << "Rear: " << cq.rearItem() << endl;

    cout << "Dequeue: " << cq.dequeue() << endl;
    cout << "Dequeue: " << cq.dequeue() << endl;

    cq.print();

    cq.enqueue(50);
    cq.enqueue(60);
    cq.enqueue(70);

    cq.print();

    cout << "Size: " << cq.size() << endl;

    cout << endl;

    cout << "===== Linked List Queue Test =====" << endl;

    MyLLQueue lq;

    lq.enqueue(100);
    lq.enqueue(200);
    lq.enqueue(300);

    lq.printAll();

    cout << "Front: " << lq.frontItem() << endl;
    cout << "Rear: " << lq.rearItem() << endl;

    cout << "Dequeue: " << lq.dequeue() << endl;

    lq.printAll();

    lq.enqueue(400);
    lq.enqueue(500);

    lq.printAll();

    cout << "Size: " << lq.size() << endl;

    lq.clear();

    lq.printAll();

    return 0;
}