#include <iostream>

class Parent {
    public:
    Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
    virtual ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};

class Child : public Parent {
    public:
    Child() : Parent() { std::cout << "Child 생성자 호출" << std::endl; }
    ~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
};

int main(){
    std::cout << "=== parent 생성 - 소멸 ===" << std::endl;
    { Parent p; }
    
    std::cout << "=== 평범한 child 생성 - 소멸 ===" << std::endl;
    { Child c; }

    std::cout << "=== parent* 로 가리킨 child 생성 - 소멸 ===" << std::endl;
    {
        /* Parent 의 소멸자를 virtual 로 만들어주지 않으면 Child 의 소멸자가 호출되지 않는다.
        근데 Parent 소멸자는 왜 호출되는가? 그건 Child 소멸자가 알아서 한다. 상속받는 사실을 알고있기 때문에 */
        Parent *p_c = new Child(); 
        delete p_c;
    }

    return 0;
}