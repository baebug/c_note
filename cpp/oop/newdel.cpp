#include <iostream>

int main(){
    int *p = new int;
    *p = 10;

    std::cout << *p << std::endl;
    
    /* new로 할당한 공간만 delete 가능 */
    delete p;

    return 0;
}