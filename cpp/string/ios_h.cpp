#include <iostream>
#include <sstream>
#include <string>

std::string to_str(int x) {
    std::ostringstream ss;
    ss << x;

    /* str 함수로 현재 문자열 스트림에 쓰여 있는 값을 불러온다. */
    return ss.str();
}

int main(){
    std::cout << "문자열로 변환 :: 1 + 2 = " << to_str(1 + 2) << std::endl;

    return 0;
}