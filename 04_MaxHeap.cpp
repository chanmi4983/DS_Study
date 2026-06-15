#include <iostream>
#include <vector>
using namespace std;

class Maxheap {
private:
    vector<int> heap;   // root 노드는 항상 index 0에 저장
    // 1번 index 기준이면:
    // parent = i / 2
    // left = i * 2
    // right = i * 2 + 1


public:
    // 부모 노드 인덱스 반환
    int parent(int i) {
        return (i - 1) / 2;
    }

    // 왼쪽 자식 노드 인덱스 반환
    int leftchild(int i) {
        return i * 2 + 1;
    }

    // 오른쪽 자식 노드 인덱스 반환
    int rightchild(int i) {
        return i * 2 + 2;
    }

    // 새로운 데이터를 heap에 삽입
    // Heapify-Up 수행
    void insert(int v) {
        heap.push_back(v);

        int index = heap.size() - 1;

        while (index > 0 && heap[parent(index)] < heap[index]) {
            int temp = heap[parent(index)];
            heap[parent(index)] = heap[index];
            heap[index] = temp;

            index = parent(index);
        }
    }

    // Root 노드 삭제
    // Heapify-Down 수행
    void removeRoot() {
        if (heap.empty()) {
            cout << "Heap is empty" << endl;
            return;
        }

        cout << "Delete Root: " << heap[0] << endl;

        heap[0] = heap[heap.size() - 1];
        heap.pop_back();

        int index = 0;

        while (true) {
            int left = leftchild(index);
            int right = rightchild(index);
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
            //swap
            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;

            index = largest;
        }
    }

    // root 값 반환
    int top() const {
        if (heap.empty()) {
            cout << "Heap is empty" << endl;
            return -1;
        }

        return heap[0];
    }

    // heap 출력
    void print() const {
        if (heap.empty()) {
            cout << "Heap is empty" << endl;
            return;
        }

        cout << "Heap: ";

        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    Maxheap h;

    cout << "===== Max Heap Test =====" << endl;

    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(10);
    h.insert(20);

    h.print();

    cout << "Top: " << h.top() << endl;

    cout << endl;
    h.removeRoot();
    h.print();

    cout << endl;
    cout << "Insert 60" << endl;
    h.insert(60);
    h.print();

    cout << "Top: " << h.top() << endl;

    return 0;
}