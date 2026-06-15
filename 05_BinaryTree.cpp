#include <iostream>
using namespace std;

// 이진 트리의 한 노드를 표현하는 클래스
class Node {
public:
    int data;       // 노드에 저장할 값
    Node* left;     // 왼쪽 자식 노드 주소
    Node* right;    // 오른쪽 자식 노드 주소

    // 생성자
    // 새 노드를 만들 때 data 값을 넣고,
    // 처음에는 왼쪽/오른쪽 자식이 없으므로 nullptr로 설정한다.
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// 전위 순회
// 순서: Root -> Left -> Right
void preorder(Node* node) {
    // 현재 노드가 없으면 더 이상 갈 곳이 없으므로 종료
    if (node == nullptr) return;

    // Root 먼저 출력
    cout << node->data << " ";

    // 왼쪽 서브트리 방문
    preorder(node->left);

    // 오른쪽 서브트리 방문
    preorder(node->right);
}

// 중위 순회
// 순서: Left -> Root -> Right
void inorder(Node* node) {
    // 현재 노드가 없으면 더 이상 갈 곳이 없으므로 종료
    if (node == nullptr) return;

    // 왼쪽 서브트리 먼저 방문
    inorder(node->left);

    // Root 출력
    cout << node->data << " ";

    // 오른쪽 서브트리 방문
    inorder(node->right);
}

// 후위 순회
// 순서: Left -> Right -> Root
void postorder(Node* node) {
    // 현재 노드가 없으면 더 이상 갈 곳이 없으므로 종료
    if (node == nullptr) return;

    // 왼쪽 서브트리 먼저 방문
    postorder(node->left);

    // 오른쪽 서브트리 방문
    postorder(node->right);

    // Root를 마지막에 출력
    cout << node->data << " ";
}

// 동적 할당한 노드들을 삭제하는 함수
// 후위 순회 방식으로 자식 노드를 먼저 삭제하고 부모를 삭제한다.
void clearTree(Node* node) {
    if (node == nullptr) return;

    clearTree(node->left);
    clearTree(node->right);

    delete node;
}

int main() {
    // 아래 모양의 이진 트리를 직접 만든다.
    //
    //          1
    //        /   \
    //       2     3
    //      / \   /
    //     4   5 6

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);

    cout << "Preorder  : ";
    preorder(root);
    cout << endl;

    cout << "Inorder   : ";
    inorder(root);
    cout << endl;

    cout << "Postorder : ";
    postorder(root);
    cout << endl;

    // new로 만든 노드들을 삭제한다.
    clearTree(root);

    return 0;
}