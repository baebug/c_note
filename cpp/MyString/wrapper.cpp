/*
정리

1. 동등한 두 객체 사이의 이항 연산자는 멤버 함수가 아닌 외부 함수로 오버로딩 하는 것이 좋다.
Complex_a.cpp 의 Complex operator+(const Complex& a, const Complex& b);

2. 한 객체만 바뀌는 등의 동등하지 않은 이항 연산자는 멤버 함수로 오버로딩 하는 것이 좋다.
Complex_a.cpp 의 Complex& operator+=(const Complex& c);

3. 단항 연산자는 멤버 함수로 오버로딩 하는 것이 좋다.
wrapper.cpp 의 Int& operator++();

4. 일부 연산자들은 반드시 멤버 함수로만 오버로딩 해야 한다.
wrapper.cpp 의 operator int() { return data; }

*/

#include <iostream>

class Int {
    int data;

    public:
    /* 복잡하게 생긴 것 같지만 결국 initializer list로 작성된 생성자와 복사생성자 이다.
    Complex(double real, double img) : real(real), img(img) {}
    
    근데 Int 객체가 int 의 Wrapper 클래스의 객체이므로 int 와 똑같이 작동하고 싶다. 
    타입 변환 연산자를 활용 : operator (변환 하고자 하는 타입)()        */
    Int(int data) : data(data) {}
    Int(const Int& i) : data(i.data) {}

    /* Int 객체가 int 변수처럼 정확히 작동하고 있는 것을 확인할 수 있다. 
        operator int() { return data; }         */

    Int& operator++() {
        data++;
        std::cout << "전위 증감 연산자" << std::endl;
        return *this;
    }

    /* 전, 후위 증감 구분을 두기 위한 int 인자 */
    Int operator++(int) {
        Int temp(*this);
        data++;
        std::cout << "후위 증감 연산자" << std::endl;
        return temp;
    }

    int get_data() const {
        return data;
    }
};

void func(const Int& i) {
    std::cout << "data : " << i.get_data() << std::endl;
}

int main(){
    Int i(3);

    func(++i);
    func(i++);
    std::cout << "data : " << i.get_data() << std::endl;

    return 0;
}