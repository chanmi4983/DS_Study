#include <iostream>
using namespace std;

// 배열 기반 Stack 클래스
class ArrayStack {
private:
    int* data;      // 스택 데이터를 저장할 동적 배열
    int maxSize;    // 스택에 저장할 수 있는 최대 크기
    int top;        // 스택의 가장 위 원소 위치를 가리키는 인덱스

public:
    // 생성자
    // ArrayStack 객체가 만들어질 때 자동으로 실행됨
    ArrayStack(int maxSize) {
        // 매개변수로 받은 maxSize를 클래스 멤버 변수 maxSize에 저장
        this->maxSize = maxSize;

        // maxSize 크기만큼 int형 배열을 동적으로 생성
        data = new int[maxSize];

        // 스택이 비어있는 상태이므로 top을 -1로 초기화
        // top == -1 이면 스택에 아무 값도 없다는 뜻
        top = -1;
    }

    // 소멸자
    // 객체 사용이 끝날 때 자동으로 실행됨
    ~ArrayStack() {
        // new로 만든 동적 배열은 delete[]로 직접 해제해야 함
        delete[] data;
    }

    // 스택이 비어있는지 확인하는 함수
    bool isEmpty() const {
        // top이 -1이면 스택이 비어있음
        return top == -1;
    }

    // 스택이 가득 찼는지 확인하는 함수
    bool isFull() const {
        // 배열의 마지막 인덱스는 maxSize - 1
        // top이 마지막 인덱스와 같으면 더 이상 push할 수 없음
        return top == maxSize - 1;
    }

    // 현재 스택에 들어있는 원소 개수를 반환하는 함수
    int size() const {
        // top은 인덱스이므로 실제 개수는 top + 1
        return top + 1;
    }

    // 스택에 값을 넣는 함수
    void push(int value) {
        // 스택이 가득 찼는지 먼저 확인
        if (isFull()) {
            cout << "Stack is full" << endl;
            return; // 더 이상 넣을 수 없으므로 함수 종료
        }

        // top을 한 칸 증가시켜 새 값을 넣을 위치로 이동
        top++;

        // 증가한 top 위치에 value 저장
        data[top] = value;
    }

    // 스택에서 가장 위의 값을 꺼내는 함수
    int pop() {
        // 스택이 비어있으면 꺼낼 값이 없음
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // 오류 상황을 표시하기 위해 -1 반환
        }

        // 현재 top 위치의 값이 스택의 가장 위에 있는 값
        int value = data[top];

        // 값을 꺼냈으므로 top을 한 칸 아래로 내림
        top--;

        // 꺼낸 값을 반환
        return value;
    }

    // 스택의 가장 위 값을 확인하는 함수
    // pop과 달리 값을 제거하지 않음
    int peek() const {
        // 스택이 비어있으면 확인할 값이 없음
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        // top 위치의 값을 반환
        // top은 줄어들지 않으므로 값이 삭제되지 않음
        return data[top];
    }

    // 스택 전체 내용을 출력하는 함수
    void print() const {
        // 스택이 비어있으면 출력할 값이 없음
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack: ";

        // 배열의 0번 인덱스부터 top 위치까지 출력
        // 0번은 가장 먼저 들어간 값
        // top 위치는 가장 나중에 들어간 값
        for (int i = 0; i <= top; i++) {
            cout << data[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    // 최대 5개의 정수를 저장할 수 있는 스택 생성
    ArrayStack s(5);

    // 스택에 값 추가
    // push는 top을 증가시키고 그 위치에 값을 저장함
    s.push(3); // data[0] = 3, top = 0
    s.push(5); // data[1] = 5, top = 1
    s.push(8); // data[2] = 8, top = 2

    // 현재 스택 출력
    // 출력: Stack: 3 5 8
    s.print();

    // pop은 가장 마지막에 들어간 값을 꺼냄
    // 현재 top 위치의 값은 8이므로 8 출력 후 제거
    cout << "pop: " << s.pop() << endl;

    // peek은 현재 가장 위의 값을 확인만 함
    // 8이 pop으로 제거되었으므로 현재 top 값은 5
    cout << "peek: " << s.peek() << endl;

    // 현재 스택에 들어있는 원소 개수 출력
    // 현재 3, 5 두 개가 남아있으므로 size는 2
    cout << "size: " << s.size() << endl;

    // pop 이후 남은 스택 출력
    // 출력: Stack: 3 5
    s.print();

    return 0;
}