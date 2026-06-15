#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int parent(int i) const {
        return (i - 1) / 2;
    }

    int leftChild(int i) const {
        return i * 2 + 1;
    }

    int rightChild(int i) const {
        return i * 2 + 2;
    }

public:
    bool isEmpty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }

    void insert(int value) {
        heap.push_back(value);

        int index = heap.size() - 1;

        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    int top() const {
        if (isEmpty()) {
            cout << "Heap is empty" << endl;
            return -1;
        }

        return heap[0];
    }

    int removeRoot() {
        if (isEmpty()) {
            cout << "Heap is empty" << endl;
            return -1;
        }

        int rootValue = heap[0];

        heap[0] = heap[heap.size() - 1];
        heap.pop_back();

        int index = 0;

        while (true) {
            int left = leftChild(index);
            int right = rightChild(index);
            int largest = index;

            if (left < heap.size() && heap[left] > heap[largest]) {
                largest = left;
            }

            if (right < heap.size() && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest == index) {
                break;
            }

            swap(heap[index], heap[largest]);
            index = largest;
        }

        return rootValue;
    }

    void print() const {
        if (isEmpty()) {
            cout << "Heap is empty" << endl;
            return;
        }

        cout << "Heap: ";

        for (int value : heap) {
            cout << value << " ";
        }

        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    heap.insert(50);
    heap.insert(40);
    heap.insert(30);
    heap.insert(20);
    heap.insert(10);

    heap.print();

    cout << "Top: " << heap.top() << endl;

    cout << "Insert 35" << endl;
    heap.insert(35);
    heap.print();

    cout << "Remove Root: " << heap.removeRoot() << endl;
    heap.print();

    cout << "Insert 60" << endl;
    heap.insert(60);
    heap.print();

    cout << "Top: " << heap.top() << endl;

    return 0;
}