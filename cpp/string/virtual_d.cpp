#include <iostream>

class Animal {
    public:
    Animal() {}
    virtual ~Animal() {}
    /* 순수 가상 함수 (pure virtual function)
    무엇을 하는지 정의되어 있지 않은 함수, = 0; 을 붙여 반드시 override 되도록 만들었다.
    이 녀석 때문에 Animal 객체의 인스턴스를 생성하는 것도 불가능하다.
    Animal 객체처럼 한 개 이상의 순수 가상함수를 포함한 클래스를 추상 클래스 (abstract class) 라고 부른다. */
    virtual void speak() = 0;
};

class Dog : public Animal {
    public:
    Dog() : Animal() {}
    void speak() override { std::cout << "월월" << std::endl; }
};

class Cat : public Animal {
    public:
    Cat() : Animal() {}
    void speak() override { std::cout << "애옹" << std::endl; }
};

int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->speak();
    cat->speak();

    return 0;
}