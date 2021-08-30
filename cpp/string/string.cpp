#include <iostream>
#include <string>

int main(){
    /* 표준이므로 std 안에 string 이 정의되어 있다. */
    std::string s = "abc";  // string 클래스의 인자를 const char * 로 받는 생성자 호출
    std::string t = "def";
    std::string s2 = s;

    std::cout << s << " 의 길이 : " << s.length() << std::endl;
    std::cout << s << " 뒤에 " << t << " 를 붙이면 : " << s + t << std::endl;

    /* string 클래스 안에 연산자 오버로딩이 되어 있겠지? */
    if (s == s2) {
        std::cout << s << " 와 " << s2 << " 는 같다. " << std::endl;
    }
    if (s != t) {
        std::cout << s << " 와 " << t << " 는 다르다. " << std::endl;
    }

    return 0;
}