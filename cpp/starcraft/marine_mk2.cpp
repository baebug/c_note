#include <iostream>
#include <string.h>

class Marine {
    /* static 멤버 변수 */
    static int total_marine_num;

    int hp;
    int coord_x, coord_y;   // 마린의 위치 (좌표)
    int damage;
    bool is_dead;

    public:
    Marine();               // 기본 생성자
    Marine(int x, int y);

    int attack() const;                       // 데미지를 리턴하므로 int type, 읽기만 하는 const 함수로 선언
    
    Marine& be_attacked(int damage_earn);  // 입는 데미지, Marine&을 리턴한다?
    
    void move(int x, int y);            // 새로운 위치를 입력받아 이동

    void show_status();                 // 상태를 보여준다.

    static void show_total_marine();    // static function

    ~Marine() { total_marine_num--; }
};
/* 초기화 후 생성자와 소멸자로 관리해주면 아주 편하다. */
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}

/* initializer list
생성자 호출과 동시에 멤버 변수들을 초기화해준다.
왜 쓰는데?
초기화 리스트: int a = 10;
기존의 생성자: int a; a = 10;
효율적인 것도 효율적인 건데, 레퍼런스와 상수처럼 생성과 동시에 초기화가 되어야 하는 경우가 있다.
*/
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {
        total_marine_num++;
    }

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {
        total_marine_num++;
    }

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}

/* const 함수: 다른 변수의 값을 바꾸지 않는 함수 */
int Marine::attack() const { return damage; }

/*
this 는 자기 자신을 가리키는 포인터. 모든 멤버 함수내에 정의되어 있다.
따라서 *this 를 리턴한다 = 내 자신을 리턴한다.
근데 Marine&을 리턴하는 게 대체 무슨 말이냐? 레퍼런스는 별명이잖아?
별명을 리턴받아서 별명에 넣어주면 새로운 별명이 생기는 개념이다.
그 별명을 수정하게 되면 본체(값)이 바뀐다.
*/
Marine& Marine::be_attacked(int damage_earn) {
    if (hp > damage_earn) {
        hp -= damage_earn;
    } else {
        hp = 0;
        is_dead = true;
    }

    return *this;
}

void Marine::show_status() {
    std::cout << " ---- 마린의 상태 ---- " << std::endl;
    std::cout << "체력 : " << hp << std::endl;
    std::cout << "위치 : (" << coord_x << ", " << coord_y << ")" << std::endl;
    if (is_dead == true) {
        std::cout << "사망" << std::endl;
    } else {
        std::cout << "생존" << std::endl;
    }
    std::cout << "현재 총 마린 수 : " << total_marine_num << std::endl << std::endl;

}

int main(){
    /* 이렇게 만들면 이름이 너무 복잡해진다.
    Marine marine1(2, 3);
    Marine marine2(3, 5);
    */

    Marine* marines[100]; // Marine 타입 포인터 100개로 이루어진 배열 marines

    marines[0] = new Marine(2, 3); // 새로운 Marine(+생성자)을 메모리에 할당하고 포인터로 가리키는 작업.
    marines[1] = new Marine(3, 5);
    // Marine marines[1](3, 5); 이렇게는 안되네

    marines[0]->show_status();  // marines[i] 는 포인터기 때문에 -> 를 사용한다.
    marines[1]->show_status();

    std::cout << "마린 1 이 마린 2 를 공격! " << std::endl;
    marines[1]->be_attacked(marines[0]->attack());

    /* 이렇게 객체(인스턴스)없이 함수가 실행 가능하다.
    객체에 종속되는 것이 아니라 클래스에 종속되기 때문
    따라서 static 변수만 사용 가능하다. (객체의 멤버변수는 모름) */
    Marine::show_total_marine();
    /* 이런 차이가 있다! (객체).(멤버함수) != (클래스)::(static함수) */

    marines[0]->show_status();
    delete marines[0];  // new 에는 delete 필수

    marines[1]->show_status();
    delete marines[1];  // 소멸자를 호출해 준 적이 없는데 알아서 호출된다. (객체가 파개될 때 자동으로 호출)

    return 0;
}