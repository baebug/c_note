/* 객체의 설계도 */
#include <iostream>

class Animal {
    /* 접근지시자, 명시하지 않으면 private */
    private:
    /* 밖에서는 인스턴스 변수, 클래스 내에서는 멤버 변수 */
    int food;
    int weight;

    public:
    /* 밖에서는 인스턴스 메서드, 클래스 내에서는 멤버 함수 */
    void set_animal(int _food, int _weight){
        food = _food;
        weight = _weight;
    }
    void increase_food(int inc){
        /* 당연히 자기 자신의 값 food, weight */
        food += inc;
        weight += (inc / 3);
    }
    void view_stat();
}; // ; 잊지말자 ;

/* 이렇게 class 안에 선언만 해두고 밖에다가 정의할 수 있다*/
void Animal::view_stat(){
    std::cout << "이 동물의 food : " << food << std::endl;
    std::cout << "이 동물의 weight : " << weight << std::endl;
}

int main() {
    /* Animal 클래스의 인스턴스 animal 생성 */
    Animal animal;
    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();

    return 0;
}