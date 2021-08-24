/*
추가/삭제/삽입이 빈번하게 일어나는 경우를 제외하고는 노드보다 배열이 낳다.
노드 말고도 큐, 스택, 트리 등의 자료 구조가 있다.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node* CreateNode(int data);
struct Node* InsertNode(struct Node* current, int data);
void DestroyNode(struct Node* destroy, struct Node* head);
void PrintNodeFrom(struct Node* from);

struct Node
{
    int data;               /* 데이터 */
    struct Node* nextNode;  /* 다음 노드를 가리키는 부분 */
};

int main(){
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(Node1, 200);
    struct Node* Node3 = InsertNode(Node2, 300);
    /* Node2 뒤에 Node4 넣기 */
    struct Node* Node4 = InsertNode(Node2, 400);

    PrintNodeFrom(Node1);

    return 0;
}

/*
struct Node => A type 이라고 할 때,
A 포인터를 반환하는 CreateNode 함수를 선언한다. (이 함수는 정수를 인자로 받음)
malloc을 통해 노드를 메모리에 할당하였고, 그것을 A 포인터 newNode가 가리킨다.
A 포인터 newNode가 가리키는(=메모리에 할당된 노드의) data에 인자로 받은 data를 넣고, nextNode에는 NULL을 넣는다.
그리고 A 포인터 newNode를 반환한다.
*/
struct Node* CreateNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->nextNode = NULL;

    return newNode;
}

/*
current라는 노드 뒤에 새로운 노드를 만들어 넣는 함수
원래 관계가 current -> after 였다면,
이 함수를 통해 current -> newNode -> after 가 된다.
*/
struct Node* InsertNode(struct Node* current, int data){
    /* current 노드가 원래 가리키고 있던 노드를 after라고 한다. */
    struct Node* after = current->nextNode;

    /* 새로운 노드를 생성한다. */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    /* 새 노드에 값을 넣어준다. */
    newNode->data = data;
    newNode->nextNode = after;

    /* current는 이제 newNode를 가리키게 된다. */
    current->nextNode = newNode;

    return newNode;
}

/*
노드를 파괴하는 역할을 가진 함수를 만들어보자.
파괴할 노드를 가리키고 있는 이전 노드가 필요하며, 그 노드를 찾기 위해서는 맨 처음 노드가 필요하다.
맨 처음 노드를 head라고 부르며, 파괴할 노드를 destroy라고 하자.
*/
void DestroyNode(struct Node* destroy, struct Node* head){
    /* 다음 노드를 가리킬 포인터, head부터 시작 */
    struct Node* next = head;

    /* 파괴할 노드가 헤드라면 */
    if (destroy == head){
        free(destroy);
        return;
    }

    /* next가 NULL이면 종료 */
    while(next){
        /* next의 다음 노드가 destroy라면 */
        if (next->nextNode == destroy){
            /* destroy가 가리키던 다음 노드를 next에 연결해준다. */
            next->nextNode = destroy->nextNode;
        }
        /* 아니면 next는 다음 노드로 넘어간다. */
        next = next->nextNode;
    }
    free(destroy);
}

void PrintNodeFrom(struct Node* from){
    /* from이 NULL일 때 까지,
    즉, 끝 부분에 도달할 때 까지 출력 */
    while(from){
        printf("데이터 : %d \n", from->data);
        from = from->nextNode;
    }

}