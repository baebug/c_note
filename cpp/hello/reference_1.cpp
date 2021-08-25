#include <iostream>

int change_val(int &p){
    p = 3;

    return 0;
}

int main(){
    int number = 5;

    std::cout << number << std::endl;
    change_val(number);
    std::cout << number << std::endl;

    return 0;
}

/*
이게 뭔데?
함수가 실행될 때 int &p = number 가 된다.
와 미쳐따..
*/