#include <iostream>
#include <string.h>

class Marine {
    int hp;
    int coord_x, coord_y;   // 마린의 위치 (좌표)
    int damage;
    bool is_dead;
    char* name;             // char 타입 포인터

    public:
    Marine();               // 기본 생성자
    Marine(int x, int y);
    Marine(int x, int y, const char* marine_name);   // x, y 좌표에 마린 생성
    ~Marine();              // 소멸자 (Destructor)

    int attack();                       // 데미지를 리턴하므로 int type
    void be_attacked(int damage_earn);  // 입는 데미지
    void move(int x, int y);            // 새로운 위치를 입력받아 이동

    void show_status();                 // 상태를 보여준다.
};

Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];   // 개행문자 들어올 공간 + 1
    strcpy(name, marine_name);                   // copy

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

Marine::~Marine() {
    std::cout << name << " 의 소멸자 호출 ! " << std::endl;
    if (name != NULL) {
        delete[] name;  // name은 char type array
    }
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return damage; }

void Marine::be_attacked(int damage_earn) {
    if (hp > damage_earn) {
        hp -= damage_earn;
    } else {
        hp = 0;
        is_dead = true;
    }
}

void Marine::show_status() {
    std::cout << " ---- 마린의 상태 ---- " << std::endl;
    std::cout << "이름 : " << name << std::endl;
    std::cout << "체력 : " << hp << std::endl;
    std::cout << "위치 : (" << coord_x << ", " << coord_y << ")" << std::endl;
    if (is_dead == true) {
        std::cout << "사망" << std::endl << std::endl;
    } else {
        std::cout << "생존" << std::endl << std::endl;
    }
}

int main(){
    /* 이렇게 만들면 이름이 너무 복잡해진다.
    Marine marine1(2, 3);
    Marine marine2(3, 5);
    */

    Marine* marines[100]; // Marine 타입 포인터 100개로 이루어진 배열 marines

    marines[0] = new Marine(2, 3, "강봉권"); // 새로운 Marine(+생성자)을 메모리에 할당하고 포인터로 가리키는 작업.
    marines[1] = new Marine(3, 5, "안태윤");
    // Marine marines[1](3, 5); 이렇게는 안되네

    marines[0]->show_status();  // marines[i] 는 포인터기 때문에 -> 를 사용한다.
    marines[1]->show_status();

    std::cout << "마린 1 이 마린 2 를 공격! " << std::endl;
    marines[1]->be_attacked(marines[0]->attack());

    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];  // new 에는 delete 필수
    delete marines[1];  // 소멸자를 호출해 준 적이 없는데 알아서 호출된다. (객체가 파개될 때 자동으로 호출)

    return 0;
}