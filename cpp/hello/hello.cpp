/* C++ 에서 표준 입출력에 필요한 것들을 포함한 헤더 (studio랑 비슷) */
#include <iostream>

/* namespace 를 이름없이 그냥 선언해줄 수 있다.
이런 경우 c언어의 static 변수, 함수 처럼 해당 파일에서만 사용 가능 */
namespace {
    int OnlyInThisFile() { return 0; }
    int only_in_this_file = 0;
}

int main(){
    /*
    std의 정체?
    - C++ 표준 라이브러리의 모든 함수, 객체 등이 정의된 이름공간(namespace)다.
    namespace가 뭔데?
    - 어떤 정의된 객체에 대해 어디 소속인지 지정해주는 것 (클래스명 느낌?) 서울::철수 != 부산::철수
    using namespace std;
    - std 이름공간 안에 저장된 모든 것들을 std:: 없이 쓰겠다. (권장되진않음)
    */
    std::cout << "hi" << std::endl
          << "my name is "
          << "Psi" << std::endl;
    
    std::cout << only_in_this_file << std::endl;
    /*
    cout: C의 stdout에 대응하는 표준 출력
    endl: 그냥 엔터(enter) 한 번 이라고 생각
    */
    return 0;
}

