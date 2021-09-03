#include <iostream>
#include <string>
using std::string;

class Vector {
    string* data;
    int capacity;
    int length;

    public:
    Vector(int n = 1);  // default argument : 1

    /* 맨 뒤에 새로운 원소를 추가한다. */
    void push_back(string s);

    /* 임의의 원소에 접근한다. */
    string operator[](int i);

    /* x 번째 위치한 원소를 제거한다. */
    void remove(int x);

    /* 벡터의 크기를 구한다. */
    int size();

    ~Vector();
};

class Stack {
    struct Node {
        Node* prev;
        string s;

        Node(Node* prev, string s) : prev(prev), s(s) {}
    };

    Node* current;  // 최상위 노드
    Node start;     // 마지막 노드에 도달하였을 때, 그 여부를 알기 위해

    public:
    Stack();

    /* 최상단 새로운 원소 추가 */
    void push(string s);

    /* 최상단 원소 제거 + 반환 */
    string pop();

    /* 최상단 원소 반환 */
    string peek();

    /* 비어있는지 체크 */
    bool is_empty();

    ~Stack();
};

/* c++ 규칙 : 디폴트 인자는 내부 선언과 외부 둘 중 한 군데에만 선언해야 한다. */
Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {}

void Vector::push_back(string s) {
    if (capacity <= length) {
        string* temp = new string[capacity * 2];
        for(int i = 0; i < length; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity *= 2;
    }

    data[length] = s;
    length++;
}

string Vector::operator[](int i) {
    return data[i];
}

void Vector::remove(int x) {
    for(int i = x + 1; i < length; i++){
        data[i - 1] = data[i];
    }
    length--;
}

int Vector::size() {
    return length;
}

Vector::~Vector() {
    if (data) {
        delete[] data;
    }
}

Stack::Stack() : start(NULL, "") { current = &start; }

void Stack::push(string s) {
    Node* n = new Node(current, s);
    current = n;
}

string Stack::pop() {
    if (current == &start) return "";

    string s = current->s;
    Node* prev = current;
    current = current->prev;

    delete prev;
    return s;
}

string Stack::peek() {
    return current->s;
}

bool Stack::is_empty() {
    if (current == &start) return true;
    return false;
}

Stack::~Stack() {
    while (current != &start) {
        Node* prev = current;
        current = current->prev;
        delete prev;
    }
}