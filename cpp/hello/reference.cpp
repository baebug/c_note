/*
#include <iostream>

int change_val(int *p){
    *p = 3;

    return 0;
}

int main(){
    int number = 5;

    std::cout << number << std::endl;
    change_val(&number);
    std::cout << number << std::endl;

    return 0;
}
*/

/* C 언어에서는 어떠한 변수를 가리키고 싶을 때 반드시 포인터를 사용해야만 했다. 
하지만 C++ 에서는 다른 변수나 상수를 가리키는 방법으로 참조자 라는 것을 제공한다. */

#include <iostream>

int main(){
    int a = 3;
    int& another_a = a;
    /* a 의 참조자 another_a 선언 (타입 뒤에 & > 타입형 참조자)
    another_a 에 어떤 작업을 수행하든 이는 사실상 a 에 하는 것과 같다?!
    조건1. 처음 선언할 때 누구의 별명인지 명시해야 함
    조건2. 한번 별명이 되면 절대로 다른 이의 별명이 될 수 없다. */

    another_a = 5;

    std::cout << "a : " << a << std::endl;                  // 5
    std::cout << "another_a : " << another_a << std::endl;  // 5

    return 0;
}