#include <stdio.h>
#include <cstring>

//봉권이 스펙
char playerName[] = "강봉권";  //플레이어의이름
int playerHP = 100;    //플레이어의체력
int playerMP = 50;    //플레이어의마력
int playerGold = 1000;   //플레이어의소지골드
int playerATK = 10;    //플레이어의공격력
int playerDEF = 5;    //플레이어의방어력
float playerCriProb = 1.5f;    //플레이어의크리티컬확률

//응답 글자수
// const int bufsize = 128;
// char buffer[bufsize] = "";
int buffer;

void title();
void prologue();
void npcDialogue(char* _name, char* _dialogue);
void charDialogue(char* _name, char* _dialogue);
void question(char* _question);

int main() {
    title();

    printf("이름: %s\n", playerName);
    printf("체력: %d\n", playerHP);

    prologue();
}

void title()
{
    printf("┌─────────────────────────────────────────┐\n");
    printf("│                                         │\n");
    printf("│");
    
    printf("\x1b[33m              강봉권의 대모험           \x1b[0m │  \n");

    printf("│                                         │\n");
    printf("│         created by \x1b[35mbaebug\x1b[0m on 2021.8.16  │\n");
    printf("└─────────────────────────────────────────┘\n");
}

void prologue()
{
    npcDialogue("상어대신", "응애");
    charDialogue("강봉권", "응애");


    question("봉권이를 죽이시겠습니까? <1. 예 or 2. 아니오>");

    if(buffer == 1)
    {
        charDialogue("강봉권", "응애");
    }
    else if(buffer == 2)
    {
        charDialogue("강봉권", "응애 고마워");
    }
    else
    {
        prologue();
    }
    
}

void charDialogue(char* _name, char* _dialogue)
{
	printf("\x1b[33m%s\x1b[0m", _name);
	printf(" : %s\n\n", _dialogue);
}

void npcDialogue(char* _name, char* _dialogue)
{
           printf("\x1b[32m%s\x1b[0m", _name);
           printf(" : %s\n\n", _dialogue);
}

void question(char* _question)
{
	printf("\x1b[36m%s \x1b[0m", _question);
    // ClearInputBuffer();
	// fgets(buffer, bufsize, stdin);
    // buffer[strlen(buffer) - 1] = '\0';
    getchar();
    scanf("%d", &buffer);
}