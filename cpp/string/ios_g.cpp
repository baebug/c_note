#include <iostream>
/* stringstream */
#include <sstream>

double to_number(std::string s) {
     /* sstream 에는 std::istringstream 이 정의되어 있는데 
    이는 문자열을 마치 하나의 스트림이라 생각하게 해주는 가상화 장치이다.
    파일에 123 이라 기록해놓고 거기서 입력받는 것과 동일 -> 파일에서 숫자를 읽는 123을 읽어냄 
    이것을 이용하면 atoi 와 같은 함수를 사용할 필요 없이 간편하게 문자열에서 숫자로 변환 가능 */
    std::istringstream ss(s);
    double x;

    ss >> x;
    return x;
}

int main(){
    std::cout << "변환 :: 1 + 2 = " << to_number("1") + to_number("2") << std::endl;

    return 0;
}