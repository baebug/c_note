/* 함수의 오버로딩
함수의 이름에 과부하를 준다. = 함수의 이름이 같아도 된다.
C++ 에서는 함수의 이름이 같더라도 인자가 다르면 다른 함수로 본다.
어떻게 구분해? 호출 하였을 때 사용하는 인자를 보고 결정한다.
인자가 일치하는 함수가 없을 경우? '자신과 최대한 근접한 함수'로 결정. 
오버로딩 규칙을 머리 속에 숙지하는 것은 아주 중요하다. 나중에 오류의 향연이.. */

#include <iostream>

void print(int x) { std::cout << "int: " << x << std::endl; }
void print(char x) { std::cout << "char: " << x << std::endl; }
void print(double x) { std::cout << "double: " << x << std::endl; }

int main(){
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    print(c);

    return 0;
}