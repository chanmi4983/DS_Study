#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int v) : data(v), next(nullptr) {}
};

class MyLLQueue
{
    Node *front;
    Node *rear;
    int count;
public:
    MyLLQueue():count(0){
        front = rear = nullptr;
    }
    MyLLQueue& operator=(const MyLLQueue&) = delete;
    MyLLQueue(const MyLLQueue&) = delete;
    ~MyLLQueue(){ clear();}
    bool isempty() const{ return count == 0;}
    void enqueue(int v);
    void dequeue();
    int getrear() const;
    int getfront() const;
    int getcount() const;
    void clear();
    void print() const;
};
void MyLLQueue::enqueue(int v){
    Node *newnode = new Node(v);
    if(isempty()){
        front = rear = newnode;
    }else {
        rear->next = newnode;
        rear = newnode;
    }
    count++;
}
void MyLLQueue::dequeue(){
    if(isempty()) return;
    Node *temp = front;
    front = front->next;
    delete temp;
    count--;
    if(isempty()) rear = nullptr;
}
int MyLLQueue::getrear() const{
    if(isempty()) return -1;
    return rear->data;
}
int MyLLQueue::getfront() const{
    if(isempty()) return -1;
    return front->data;
}
int MyLLQueue::getcount() const{
    return count;
}
void MyLLQueue::clear(){
    while(!isempty()) dequeue();
}
void MyLLQueue::print() const{
    Node *cur = front;
    while(cur != nullptr){
        cout << cur->data << endl;
        cur = cur->next;
    }
}

int main()
{
    return 0;
}