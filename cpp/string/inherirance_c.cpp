#include <iostream>
#include <string>

class Base {
    std::string s;

    public:
    Base() : s("기반") { std::cout << "기반 클래스 생성" << std::endl; }

    void what() { std::cout << "base 의 what() - " << s << std::endl; }
};

class Derived : public Base {
    std::string s;

    public:
    Derived() : s("파생"), Base() { std::cout << "파생 클래스 생성" << std::endl; }

    void what() { std::cout << "derived 의 what() - " << s << std::endl; }
};

int main(){
    Base p;
    Derived c;

    std::cout << "=== 포인터 버젼 ===" << std::endl;
    Base* p_c = &c;
    Derived* p_c2 = &c;

    /* 이것이 업 캐스팅, 기반의 포인터로 파생을 가리킬 수 있다. (is-a 관계의 파생에는 기반이 포함되어 있기 때문에)
    반대의 경우인 다운 캐스팅은 권장되지 않는다. */
    p_c->what();        // Base 의 포인터 p_c 는 c 안에 있는 base 부분을 가리키고 있기 때문에 base 의 what() 이 실행된다.
    p_c2->what();       // Derived 의 포인터 p_c2 이므로 derived 의 what() 이 실행된다.

    return 0;
}