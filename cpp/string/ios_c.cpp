/* 파일 스트림은 기본적인 istream 이나 ostream 클래스보다 더 지원하는 기능이 많기 때문에
이를 상속 받아서 작성되었으며(ifstream, ofstream), 모두 포함하는 라이브러리는 fsream 이다. */

#include <fstream>
#include <iostream>
#include <string>

int main(){
    /* 파일 읽기 준비 */
    std::ifstream in("test.txt");   // 두 번째 인자로 std::ios::binary 를 주면 이진 그대로의 값 받음 (default: 문자열)
    // in.read((char*)(&x), 4);     무슨 뜻인지 잘 모르겠음. int 변수를 마치 4바이트 짜리 char 배열이라고 생각해라. 라는데
    std::string s;

    /* is_open 은 istream 에는 없지만 ifstream 에서 상속받으면서 추가된 함수
    ifstream 객체의 소멸자에서 자동으로 fclose 를 수행한다.
    하지만 다른 파일을 읽기 위해서는 직접 in.close()를 한 뒤, in.open("other.txt") 를 해주어야 한다. */
    if (in.is_open()) {
        /* cin 과 마찬가지로 공백 문자가 나올 때 까지 읽는다. */
        in >> s;
        std::cout << "입력 받은 문자열 :: " << s << std::endl;
    } else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }

    return 0;
}