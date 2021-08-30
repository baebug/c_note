#include <iostream>
#include <string>

class Base {
    std::string s;

    public:
    Base() : s("기반") {    // default 생성자 : s 에 "기반" 이라는 string 이 들어감
        std::cout << "기반 클래스" << std::endl;
    }

    void what() {
        std::cout << s << std::endl;
    }
};

/* 보통 부모 - 자식 클래스 라고 부르는데
C++ 의 경우 하위 클래스가 여러 클래스에게 상속받을 수 있기 때문에
기반 - 파생 클래스 라고 부르는게 낫다고 본다. */

/* 클래스 Derived 가 클래스 Base 를 public 형식으로 상속받겠다. */
class Derived : public Base {
    std::string s;

    public:
    /* 기반의 생성자를 호출해서 기반의 생성을 먼저 처리한 다음, Derived 의 생성자가 실행되어야 한다. */
    Derived() : Base(), s("파생") {
        std::cout << "파생 클래스" << std::endl;

        /* 함수 what()은 Base 클래스에만 정의되어 있으므로 Base 클래스의 what()이 실행된다. 
        Derived 클래스에도 함수 what()이 정의되어 있다면 Derived 클래스의 what()이 실행된다.
        이것이 바로 오버라이딩(overriding) 이다. (Derived 의 what 함수가 Base 의 what 함수를 오버라이딩 함) */
        what();
    }
};

int main(){
    std::cout << " === 기반 클래스 생성 === " << std::endl;
    Base p;

    std::cout << " === 파생 클래스 생성 === " << std::endl;
    Derived c;

    return 0;
}