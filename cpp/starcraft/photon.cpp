/* 경고
C++ 에서도 name 을 const char* 방식(널 종료 char 배열) 으로 다루는 것은
매우 매우 매우 매우 매우 매우 비추되는 방식이므로 뒤의 강의도 보고 배우자.
*/
#include <iostream>
#include <string.h>

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char *name;

    public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(int x, int y, const char *cannon_name);
    Photon_Cannon(const Photon_Cannon& pc);
    ~Photon_Cannon();

    void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
    std::cout << "생성자 호출 !" << std::endl;
    coord_x = x;
    coord_y = y;
    hp = shield = 100;
    damage = 20;

    name = NULL;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) {
    std::cout << "생성자 호출 !" << std::endl;
    coord_x = x;
    coord_y = y;
    hp = shield = 100;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}

// /* T(const T& a) - 복사 생성자의 정석 */
// /* 사실 이미 C++에서는 default copy cinstructor 를 지원해주고 있다. 
// 따라서 이 코드를 주석처리 하고 run 해도 동일한 결과가 나온다. 맞네
// 하지만 default copy constructor 에서 지원하는 것은 얕은 복사 이므로 한계가 있다. */
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
    std::cout << "복사 생성자 호출 !" << std::endl;
    /* 상수 레퍼런스(const)로 받았기 때문에 내부에서 변경 불가(pc.hp = 50)
    이런식으로 함수 내부에서 받은 인자의 값을 변경하는 일이 없다면 꼭 const를 습관화하자 */
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;

    /* 깊은 복사 */
    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}

Photon_Cannon::~Photon_Cannon() {
    /*
    name 이 있으면 0이 아닌 값이 나올테고
    그러면 if문 안에서 true 로 처리 된다.
    */
    if (name) delete[] name;
}

void Photon_Cannon::show_status() {
    std::cout << " ---- 포토 캐논 ---- " << std::endl;
    std::cout << "이름 : " << name << std::endl;
    std::cout << "체력 : " << hp << std::endl;
    std::cout << "실드 : " << shield << std::endl;
    std::cout << "위치 : (" << coord_x << ", " << coord_y << ")" << std::endl;
}

int main(){
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2(pc1);
    Photon_Cannon pc3 = pc2;    // 컴파일러가 Photon_Cannon pc3(pc2); 로 해석한다.

    pc1.show_status();
    pc2.show_status();
    pc3.show_status();

    return 0;
}

