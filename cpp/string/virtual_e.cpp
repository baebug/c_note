#include <iostream>

class A {
    public:
    int a;
};

class B {
    public:
    int b;
};

/* 상속 순서에 따라 생성자가 호출된다. */
class C : public A, public B {
    public:
    int c;
};

