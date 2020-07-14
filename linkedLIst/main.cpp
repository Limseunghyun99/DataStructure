#include<iostream>;
#include"LinkedHead.h";

using namespace std;
int singleList2::length=0;
Node* singleList2::head=nullptr;

Node* Node::create(int input) { //Node class 하위 create 함수 정의
    Node* node = new Node; //Node 클래스로 새 노드 생성
    node->data = input; // Node data 에 input 저장
    node->nextNode = NULL;
    return node;
}

void Node::deleteNode(Node *node) {
   delete node;
}


int singleList2::appendNode(Node* node) {
    if(this->head == NULL) { //헤드가 존재 하지 않는 경우 singleList2의 헤드를 지금 노드로 지정
        this->head = node;
        singleList2::length++;;
        return 1; // 의도한 대로 실행되지 않았기 때문에 1 리턴
    } else { // 헤드가 존재하는 경우 current 노드 생성 후 헤드 저장
        Node* current = this->head;
        while(current->nextNode != NULL) { // 다음 노드가 존재하지 않을때 까지 이동
            current = current->nextNode;
        }
        current->nextNode = node; // 마지막 노드가 현재 노드를 가리키도록 세팅

        singleList2::length++;

        return 0; // 제대로 동작 했으므로 0 리턴
    }
}

Node* singleList2::getNode(int index) {

    Node* current = this->head;
    if (index <0 || singleList2::length < index){
        cout<<"Out of Range"<<endl;
        return NULL; // 여길 어떻게 해야할까
    }

    while(index--) { //index 값을 줄여가면서 타겟 노드로 접근
        current = current->nextNode;
    }

    return current;
}

int singleList2::removeNode(int index) {
        if (singleList2::length==0 || singleList2::length<index || index<=0){
            cout<<"List is empty or out of range"<<endl;
            return 1; //Error
        }

		Node *tmp;
		Node *cur = this->head; // cur을 맨 처음 노드로 맞춰놓고

		for(int i = 0;i<index;++i)
		{
            cur = cur->nextNode;
		}

		tmp = cur->nextNode; // 삭제할 노드는 cur 다음의 노드이므로 이를 tmp에 저장
		cur->nextNode = cur->nextNode->nextNode; // cur의 next 포인터에 cur의 다음 다음 노드를 연결

		free(tmp); // 삭제하려는 노드는 메모리를 해제시킨다
		delete(tmp);
		singleList2::length--; // 삭제 후 리스트 길이 감소
		return SUCCESS; //Success
}

int singleList2::insertAfter(int index, Node* target){
    if (index>singleList2::length || index<0){
            cout<<"Out of Range"<<endl;
            return 1; //ERROR
    }
    else if(singleList2::length == 0){
            cout<<"There's No Available List"<< endl;
        return 1; //ERROR
    }
        Node *cur=singleList2::getNode(index); //index번의 노드

        target ->nextNode= cur->nextNode; // 기존 노드가 가지고 있던 포인터 받아옴
        cur ->nextNode=target; // 기존 노드 -> 삽입 노드 -> 다음 노드
        singleList2::length++;
        return 0; //SUCCESS
}

int singleList2::display() {
    if(this->head == NULL) { // 빈 리스트면
        cout << "Empty List!" << endl; //표시하고
        return 1; //함수 종료
    }
    Node* current = this->head; //빈리스트가 아니면 헤드 노드로 점프
    cout << "LinkedList: \n"; // 표시 시작
    while(current != NULL) { // 끝까지 돌면서
       cout << current->data << " \n"; // 함수 데이터 출력
       current = current->nextNode; // 다음 노드로 이동
    }
    cout << "END\n\n" << endl;
    return 0; //Success
}

int singleList2::getLength() { // 리스트 총 길이 리턴(원소가몇개인지)

    return singleList2::length; //길이 리턴
}

    int singleList2::init() {
        this->head = NULL; //헤드 널로 초기화
    };

int singleList2::setHead(Node* node){
    this ->head = node;
}




int main(void) {
    singleList2().init(); // 초기화
    Node* firstNode = Node().create(0); // 리스트 생성
    singleList2().setHead(firstNode); // 헤드 설정

    Node* SecondNode = Node().create(1); // 리스트 생성
    singleList2().appendNode(SecondNode); // 리스트 추가

    Node* thirdNode = Node().create(2); // 리스트 생성
    singleList2().appendNode(thirdNode); // 리스트 추가

    Node* fourthNode = Node().create(3); // 리스트 생성
    singleList2().appendNode(fourthNode); // 리스트 추가

    Node* fifthNode = Node().create(4); // 리스트 생성
    singleList2().appendNode(fifthNode); // 리스트 추가

    Node* sixthNode = Node().create(5); // 리스트 생성
    singleList2().appendNode(sixthNode); // 리스트 추가

/*removeNode() test
    singleList2().display(); // 삭제하기 전 리스트
    cout<<"4번째 노드 삭제 후 결과\n "<< endl;
    singleList2().removeNode(3);// 4번째 노드 삭제
    singleList2().removeNode(-20);// 에러 테스트
*/


/* getNode() Test
    Node* tmp = singleList2().getNode(3);
    cout<<"4번째 Node는 :"<< tmp->data << endl;
*/
/*
// getNode 음수 인덱스 처리 리턴 생각해봐야함
    Node* tmp = singleList2().getNode(-1);
    cout<<"에러 테스트 -1번째  :"<< tmp->data << endl;
*/

/*
//insertAfter() Test  index
    singleList2().display(); // 추가하기 전 리스트
    Node* tmp = Node().create(777); // 추가할 노드
    singleList2().insertAfter(-1,tmp); // 삽입
*/
    singleList2()

    singleList2().display(); // 출력
    return 0;
}
