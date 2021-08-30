#include <iostream>

class A {
    private:
    void private_func(){}
    int private_num;

    /* B 는 A 의 친구 */
    friend class B;

    /* func 는 A 의 친구 */
    friend void func();
};

class B {
    public:
    void b() {
        A a;

        /* private 필드의 함수와 변수지만 B 는 A 의 친구이기 때문에 접근할 수 있다. */
        a.private_func();
        a.private_num = 2;
        std::cout << "B 를 통한 A 의 private 접근" << std::endl;
        std::cout << "a.private_num : " << a.private_num << std::endl;
    }
};

void func() {
    A a;

    /* private 필드의 함수와 변수지만 func 는 A 의 친구이기 때문에 접근할 수 있다. */
    a.private_func();
    a.private_num = 3;
    std::cout << "func 를 통한 A 의 private 접근" << std::endl;
    std::cout << "a.private_num : " << a.private_num << std::endl;
}

int main() {
    /* 하지만 A 는 B 의 private 에 접근할 수 없다.. */
    B bong;
    bong.b();

    func();

    return 0;
}