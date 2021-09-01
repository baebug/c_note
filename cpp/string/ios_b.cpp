/* 버퍼에 데이터가 얼마나 쌓여있든지 간에 바로 출력해주는 flush 함수
std::endl (조작자)는 스트림에 '\n'을 출력하는 것과 더불어 flush 기능을 수행해준다. 

stream : 문자들의 순차적인 나열, 문자들이 쪼르르르륵 들어온다.
streambuf 클래스에서는 입력 버퍼와 출력 버퍼를 구분해서 각각 get area, put area 라고 부른다.

C++ 입출력 라이브러리는 스트림 버퍼도 추상화해서 클래스로 만들었다. 가 핵심 요점
*/

#include <string>
#include <iostream>

int main(){
    std::string s;
    std::cin >> s;

    // 위치 지정자를 한 칸 옮기고, 그 다음 문자를 훔쳐본다 (아직 움직이지 않음)
    char peek = std::cin.rdbuf()->snextc();
    if (std::cin.fail()) std::cout << "Failed";
    std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
    std::cin >> s;
    std::cout << "다시 읽으면 : " << s << std::endl;

    return 0;
}

/* std::cin.rdbuf() 를 호출하면 / cin 객체가 / 입력을 수행하던 streambuf 객체를 가리키는 포인터를 리턴한다.
현재 streambuf 는 입력만을 수행하고 있기 때문에, 이 streambuf 객체에는 get area 만 존재한다.
snextc() 함수를 스트림 위치 지정자를 한 칸 전진시킨 후, 그 자리에 해당하는 문자를 엿본다.
엿보는 거랑 읽는 거랑은 다른 게, 읽으면 위치 지정자가 한 칸 전진한다. */