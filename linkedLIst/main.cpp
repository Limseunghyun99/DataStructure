#include<iostream>;
#include"LinkedHead.h";

using namespace std;
int singleList2::length=0;
Node* singleList2::head=nullptr;

Node* Node::create(int input) { //Node class ���� create �Լ� ����
    Node* node = new Node; //Node Ŭ������ �� ��� ����
    node->data = input; // Node data �� input ����
    node->nextNode = NULL;
    return node;
}

void Node::deleteNode(Node *node) {
   delete node;
}


int singleList2::appendNode(Node* node) {
    if(this->head == NULL) { //��尡 ���� ���� �ʴ� ��� singleList2�� ��带 ���� ���� ����
        this->head = node;
        singleList2::length++;;
        return 1; // �ǵ��� ��� ������� �ʾұ� ������ 1 ����
    } else { // ��尡 �����ϴ� ��� current ��� ���� �� ��� ����
        Node* current = this->head;
        while(current->nextNode != NULL) { // ���� ��尡 �������� ������ ���� �̵�
            current = current->nextNode;
        }
        current->nextNode = node; // ������ ��尡 ���� ��带 ����Ű���� ����

        singleList2::length++;

        return 0; // ����� ���� �����Ƿ� 0 ����
    }
}

Node* singleList2::getNode(int index) {

    Node* current = this->head;
    if (index <0 || singleList2::length < index){
        cout<<"Out of Range"<<endl;
        return NULL; // ���� ��� �ؾ��ұ�
    }

    while(index--) { //index ���� �ٿ����鼭 Ÿ�� ���� ����
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
		Node *cur = this->head; // cur�� �� ó�� ���� �������

		for(int i = 0;i<index;++i)
		{
            cur = cur->nextNode;
		}

		tmp = cur->nextNode; // ������ ���� cur ������ ����̹Ƿ� �̸� tmp�� ����
		cur->nextNode = cur->nextNode->nextNode; // cur�� next �����Ϳ� cur�� ���� ���� ��带 ����

		free(tmp); // �����Ϸ��� ���� �޸𸮸� ������Ų��
		delete(tmp);
		singleList2::length--; // ���� �� ����Ʈ ���� ����
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
        Node *cur=singleList2::getNode(index); //index���� ���

        target ->nextNode= cur->nextNode; // ���� ��尡 ������ �ִ� ������ �޾ƿ�
        cur ->nextNode=target; // ���� ��� -> ���� ��� -> ���� ���
        singleList2::length++;
        return 0; //SUCCESS
}

int singleList2::display() {
    if(this->head == NULL) { // �� ����Ʈ��
        cout << "Empty List!" << endl; //ǥ���ϰ�
        return 1; //�Լ� ����
    }
    Node* current = this->head; //�󸮽�Ʈ�� �ƴϸ� ��� ���� ����
    cout << "LinkedList: \n"; // ǥ�� ����
    while(current != NULL) { // ������ ���鼭
       cout << current->data << " \n"; // �Լ� ������ ���
       current = current->nextNode; // ���� ���� �̵�
    }
    cout << "END\n\n" << endl;
    return 0; //Success
}

int singleList2::getLength() { // ����Ʈ �� ���� ����(���Ұ������)

    return singleList2::length; //���� ����
}

    int singleList2::init() {
        this->head = NULL; //��� �η� �ʱ�ȭ
    };

int singleList2::setHead(Node* node){
    this ->head = node;
}




int main(void) {
    singleList2().init(); // �ʱ�ȭ
    Node* firstNode = Node().create(0); // ����Ʈ ����
    singleList2().setHead(firstNode); // ��� ����

    Node* SecondNode = Node().create(1); // ����Ʈ ����
    singleList2().appendNode(SecondNode); // ����Ʈ �߰�

    Node* thirdNode = Node().create(2); // ����Ʈ ����
    singleList2().appendNode(thirdNode); // ����Ʈ �߰�

    Node* fourthNode = Node().create(3); // ����Ʈ ����
    singleList2().appendNode(fourthNode); // ����Ʈ �߰�

    Node* fifthNode = Node().create(4); // ����Ʈ ����
    singleList2().appendNode(fifthNode); // ����Ʈ �߰�

    Node* sixthNode = Node().create(5); // ����Ʈ ����
    singleList2().appendNode(sixthNode); // ����Ʈ �߰�

/*removeNode() test
    singleList2().display(); // �����ϱ� �� ����Ʈ
    cout<<"4��° ��� ���� �� ���\n "<< endl;
    singleList2().removeNode(3);// 4��° ��� ����
    singleList2().removeNode(-20);// ���� �׽�Ʈ
*/


/* getNode() Test
    Node* tmp = singleList2().getNode(3);
    cout<<"4��° Node�� :"<< tmp->data << endl;
*/
/*
// getNode ���� �ε��� ó�� ���� �����غ�����
    Node* tmp = singleList2().getNode(-1);
    cout<<"���� �׽�Ʈ -1��°  :"<< tmp->data << endl;
*/

/*
//insertAfter() Test  index
    singleList2().display(); // �߰��ϱ� �� ����Ʈ
    Node* tmp = Node().create(777); // �߰��� ���
    singleList2().insertAfter(-1,tmp); // ����
*/
    singleList2()

    singleList2().display(); // ���
    return 0;
}
