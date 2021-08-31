/* 레퍼런스도 virtual 작동한다. */

#include <iostream>

class A {
    public:
    virtual void show() { std::cout << "Parent !" << std::endl; }
};

class B : public A {
    public:
    void show() override { std::cout << "Child !" << std::endl; }
};

void test(A& a) { a.show(); }

int main(){
    A a;
    B b;
    test(a);
    test(b);

    return 0;
}

/* 다 가상함수 (virtual function) 으로 만들면 안되나요?
전부 다 가상 함수라고 해서 작동 안하거나 그런건 없음, java는 default 가 가상 함수
but, 가상 함수가 하나라도 존재하는 클래스는 vtable (전화번호부) 가 생기고 
가상 함수를 사용하면 전화번호부를 찾아본다. -> 속도 저하            */