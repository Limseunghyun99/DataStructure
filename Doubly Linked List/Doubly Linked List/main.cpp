#include <iostream>
#include "Double.h"

using namespace std;

Node* DoublyLinkedList::createNode(int input)
{
    Node* tmp = new Node;;                                          //임시로 노드 생성
    tmp->data = input;                                              //입력값을 데이터로 설정
    tmp->nextNode = nullptr;                                       //다음 포인터를 null로 설정
    tmp->preNode = nullptr;                                        //이전 포인터를 null로 설정
    return tmp;
}

int DoublyLinkedList::setHead(Node* target)
{
    if (this->length == 0)                                   // 길이가 0이면
    {
       this->head = target;                                  //헤드 설정
       return ERROR;
    }
    else if (this -> head == nullptr)
    {
        this->head = target;
    }
    else                                                          // 이미 헤드가 존재하면
    {
    target->nextNode = this->head;                          //입력 -> 기존 헤드
    this->head->preNode = target;                           //입력 <- 기존헤드
    this->head = target;                                    // 새 헤드 <=> 기존 헤드
    }

    return SUCCESS;
}

int DoublyLinkedList::getLength()
{
    int tmp = this->length;
    return tmp;
}

int DoublyLinkedList::appendNode(Node* target)
{
    if(this->head == nullptr)                               // 헤드가 null
    {
        cout<<"Head is null,appendNode\n"<<endl;
        this->head = target;                                 //헤드로 설정
        this->length++;                                      // 길이 추가
        return ERROR;                                             //실패
    }
    else
    {
        Node* tmp = this->head;                              // 헤드에 접근
        while(tmp->nextNode != nullptr)                           // 끝까지
        {
            tmp= tmp->nextNode;
                                                                   // 이동
        }
        tmp->nextNode=target;                                      // 맨 뒤에 입력 노드 붙임
        target->preNode = tmp;                                     // 이전 노드로 연결
        this->length++;                                      // 길이 추가
    return SUCCESS;
}
}

Node* DoublyLinkedList::getNode(int index)
{
    Node* tmp = this->head;                                  //헤드 접근
    if (this->head == nullptr){                             // 헤드가 null이면
        std::cout<<"Head is null"<<endl;
        return nullptr;                         // 에러출력
    }
    else if(this->length <index)                            // 인덱스가 길이보다 길면
    {
        std::cout<<"Index is out of range"<<endl;
        return nullptr;                 //에러 출력
    }
    else{
        for(int i=0;i<index;i++)                                  // index만큼 이동
        {
            tmp=tmp->nextNode;                                     //이동
        }
    }
    return tmp;                                                   //노드 리턴
}

int DoublyLinkedList::insertNode(int index, Node* target)
{
    if (this->head == nullptr)                               //헤드가 null
    {
        std::cout<<"Head is null"<<endl;                           //메세지
        this->head = target;                                  // 입력 노드를 헤드로
        this->length++;                                       // 길이 추가
        return ERROR;
    }
    else if(this->length <index)                             // 인덱스가 길이보다 길면
    {
        std::cout<<"Index is out of range"<<endl;                  //에러 출력
        return ERROR;
    }
    else{
        Node* tmp=this->head;                                 //헤드 접근
        for (int i=0;i<index;i++)                                  // 인덱스 만큼
        {
            tmp=tmp->nextNode;                                      // 이동
        }
        target->preNode = tmp->preNode;
        target->nextNode = tmp;
        tmp->preNode->nextNode = target;
        tmp->preNode = target;
        this->length++;                                       // 길이 추가
    }
    return SUCCESS;

}

int DoublyLinkedList::removeNode(int index)
{
    if (this->head == nullptr){
        std::cout<<"Head is null"<<endl;
        return ERROR;
    }
    else if(this->length <index)                              // 인덱스가 길이보다 길면
    {
        std::cout<<"Index is out of range"<<endl;                  //에러 출력
        return ERROR;
    }
    else if(index == 1)
    {
        this->head = this->head->nextNode;
        return ERROR;
    }
    else if(index == this->length)
    {
        Node* tmp=this->head;
        for (int i=0;i<index;i++)                                  //인덱스만큼 이동
        {
            tmp = tmp->nextNode;                                    //이동
        }
        tmp->preNode->nextNode = nullptr
        free(tmp)
        return ERROR;
    }
    else{
        Node* tmp=this->head;
        for (int i=0;i<index;i++)                                  //인덱스만큼 이동
        {
            tmp = tmp->nextNode;                                    //이동
        }
        tmp->preNode->nextNode = tmp->nextNode;                     //이전 노드를 다음 노드에 연결
        tmp->nextNode->preNode = tmp->preNode;                      // 다음 노드를 이전 노드에 연결
        free(tmp);                                                  // 메모리 해제
        this->length--;                                       // 길이 감소
    }
    return SUCCESS;
}

int DoublyLinkedList::display()
{
    if (this->head == nullptr){                              // 빈 리스트면
        cout << "Empty List!" << endl;                             //표시하고
        return ERROR;                                              //함수 종료
    }
    Node* current = this->head;                               //빈리스트가 아니면 헤드 노드로 점프
    cout << "Doubly Linked List: \n"<<endl;                        // 표시 시작
    while(current->nextNode != nullptr)
    {
    cout << current->data << " \n"<<endl;;                         // 함수 데이터 출력
    current = current->nextNode;                                    // 다음 노드로 이동
    }
    cout << "Last Node: "<<current->data << " \n"<<endl;;          // 함수 데이터 출력

    return SUCCESS;                                                //Success
}


int main()
{
    DoublyLinkedList* list_1 = new DoublyLinkedList;

    Node* first = DoublyLinkedList().createNode(1);
    Node* second = DoublyLinkedList().createNode(2);
    Node* three = DoublyLinkedList().createNode(3);
    Node* four = DoublyLinkedList().createNode(4);
    Node* five = DoublyLinkedList().createNode(5);
    Node* ten = DoublyLinkedList().createNode(10);

    list_1.setHead(first);

    list_1.appendNode(second);
    list_1.appendNode(three);
    list_1.appendNode(four);
    list_1.appendNode(five);
    //removeNode Test
    //list_1.removeNode(3);
    //insert Node Test
    // list_1.insertNode(3,ten);

    int len = list_1.getLength();
    cout << "Length is " <<len<<endl;


    list_1.display();
    std::cout<<"Test Functions End\n"<<endl;
    return 0;
}
