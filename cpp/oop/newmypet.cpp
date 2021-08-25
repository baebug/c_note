/*
    C 의 한계
    Animal 키우기 게임이 흥행해서 Bird와 Fish로 확장판이 등장.
    각각 새로운 구조체 내부의 변수를 가질 때 그걸 하나하나 추가해주고,
    각 구조체에 맞는 함수를 또 만들어주고... 이걸 다 언제하냐 이거야!

    두둥! 객체지향프로그래밍!
*/


#include <iostream>
/* struct Animal 을 선언하고 typedef 를 통해 Animal로 명명했다. */
typedef struct Animal
{
    char name[30];
    int age;
    int health;
    int food;
    int clean;
} Animal;

void create_Animal(Animal *animal);
void play(Animal *animal);
void show_stat(Animal *animal);
void one_day_pass(Animal *animal);

int main(){
    /* Animal 구조체를 가리키는 포인터 로 이루어진 list(이름) 배열을 선언 (원소 10개) */
    Animal *list[10];
    int animal_num = 0;

    for(;;) {
        std::cout << "1. 동물 추가하기" << std::endl;
        std::cout << "2. 놀기" << std::endl;
        std::cout << "3. 상태 보기" << std::endl;

        int input;
        std::cin >> input;

        switch (input){
            int play_with;
            case 1:
                /* list 배열의 비어있는 포인터에게 새로운 Animal 구조체를 가리키게 한다. */
                list[animal_num] = new Animal;
                /* create_Animal 함수에 Animal 구조체 포인터를 넣는다. */
                create_Animal(list[animal_num]);

                animal_num++;
                break;
            case 2:
                std::cout << "누구랑 놀아줄래? " << std::endl;
                std::cin >> play_with;

                if(play_with < animal_num) play(list[play_with]);
                break;

            case 3:
                std::cout << "누구의 상태를 볼래? " << std::endl;
                std::cin >> play_with;

                if(play_with < animal_num) show_stat(list[play_with]);
                break;
        }

        for(int i = 0; i != animal_num; i++){
            one_day_pass(list[i]);
        }
    }
    /* 무한루프가 끝날 때, (프로그램이 종료될 때)
    new 로 할당된 메모리들을 delete 를 통해 free 시켜준다. */
    for(int i = 0; i != animal_num; i++){
        delete list[i];
    }

    return 0;
}

void create_Animal(Animal *animal){
    /* 인자로 들어온 Animal 구조체 포인터(list[i])의 이름을 animal이라고 명명한다.
    그리고 그 animal 이 가리키는 구조체 내부의 변수에 값들을 넣어주는 과정 */
    std::cout << "동물 이름은 뭔가요? " << std::endl;
    std::cin >> animal->name;

    std::cout << "동물 나이는 몇 살 인가요? " << std::endl;
    std::cin >> animal->age;
    
    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;

}

void play(Animal *animal){
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;

}

void show_stat(Animal *animal){
    std::cout << " ----- 상태 보기 ----- " << std::endl;
    std::cout << "이름   : " << animal->name << std::endl;
    std::cout << "나이   : " << animal->age << std::endl;
    std::cout << "건강   : " << animal->health << std::endl;
    std::cout << "배부름 : " << animal->food << std::endl;
    std::cout << "청결   : " << animal->clean << std::endl;

}

void one_day_pass(Animal *animal){
    animal->health -= 10;
    animal->food -= 10;
    animal->clean -= 10;
}
