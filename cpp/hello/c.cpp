#include <iostream>

int main(){
    int i, sum = 0;

    for(i = 0; i < 10; i++){
        sum += i;
        std::cout << i << " 까지의 합 누적 : " << sum << std::endl;
    }
    return 0;
}

/* std::cin >> input; 
타입도 신경 안 써도 됨. 헐.. */