#define SUCCESS 0
#define ERROR 1

#ifndef Node_H //Node class가 정의되어 있지 않다면
#define Node_H //Node 정의
class Node{
    public:
            int data; //Node에 저장되는 데이터
            Node* nextNode=nullptr; // 다음 노드를 가리키는 포인터
            Node* create(int data); // 입력 값을 갖는 노드 생성
            void deleteNode(Node *node); //입력된 노드를 삭제
};
#endif // 정의 끝

#ifndef singleList2_H //singleList2가 정의되지 않았다면
#define singleList2_H // singleList2를 정의한다.
class singleList2 {
    private:
        static int length; //list 전체 길이
    public:
        static Node* head; //list 시작 노드를 가리킨다
        int setHead(Node* node); // Head노드로 지정
        int appendNode(Node* node); // 노드를 리스트 끝에 추가한다.
        Node* getNode(int index); // 인덱스에 해당하는 노드를 리턴한다.
        int removeNode(int index); // 인덱스에 해당하는 노드를 삭제한다.
        int insertAfter(int index, Node* target);// 인덱스 위치에 target노드를 추가한다.
        int display(); // 리스트를 출력한다.
        int getLength(); //리스트 전체 길이를 리턴한다.
        int init(); // 리스트를 생성 및 초기화한다.
};
#endif






