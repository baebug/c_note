#include <iostream>

class Base {

    public:
    Base() { std::cout << "기반 클래스 생성" << std::endl; }

    /* virtual : 녹아서 없어지는 건가? -- 동적 바인딩
    
    흠.. p_c 는 Base 포인터니까 Base 의 what() 을 실행해야겠다. 
    어? 근데 what() 이 virtual function 이네? 여기 Base 객체 맞어?

    Y : 맞구나. 그럼 Base 의 what() 실행!
    N : 엥 Derived 객체잖아? 그럼 Derived 의 what() 실행!        */
    
    virtual void what() { std::cout << "base 의 what() " << std::endl; }
};

class Derived : public Base {

    public:
    Derived() : Base() { std::cout << "파생 클래스 생성" << std::endl; }

    /* override 키워드를 통해 실수를 방지할 수 있다. 쌍으로 연결해 줌 */
    void what() override { std::cout << "derived 의 what() " << std::endl; }
};

int main(){
    Base p;
    Derived c;

    Base* p_p = &p;
    Base* p_c = &c;

    std::cout << " == 실제 객체는 Base == " << std::endl;
    p_p->what();

    std::cout << " == 실제 객체는 Derived == " << std::endl;
    p_c->what();

    return 0;
}