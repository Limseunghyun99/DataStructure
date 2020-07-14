#include<iostream>;
#include<LinkedHead.h>;

using namespace std;

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
        return 1; // �ǵ��� ��� ������� �ʾұ� ������ 1 ����
    } else { // ��尡 �����ϴ� ��� current ��� ���� �� ��� ����
        Node* current = this->head;
        while(current->nextNode != NULL) { // ���� ��尡 �������� ������ ���� �̵�
            current = current->nextNode;
        }
        current->nextNode = node; // ������ ��尡 ���� ��带 ����Ű���� ����

        singleList2.length++;
        return 0; // ����� ���� �����Ƿ� 0 ����
    }
}

Node* singleList2::getNode(int index) {

    Node* current = this->head;

    while(index--) { //index ���� �ٿ����鼭 Ÿ�� ���� ����
        current = current->nextNode;
    }

    return current;
}

int singleList2::removeNode(int index) {

        if (singleList2.length==0 || singleList2.length<index || index<=0){
            cout<<"List is empty or out of range"<<endl;
            return 1; //Error
        }

		Node *tmp;
		Node *cur = this->head; // cur�� �� ó�� ���� �������
		int i = index;
		for(int i = index; i>=0);--i){
            cur = cur->nextNode;
		}

		tmp = cur->nextNode; // ������ ���� cur ������ ����̹Ƿ� �̸� tmp�� ����
		cur->nextNode = cur->nextNode->nextNode; // cur�� next �����Ϳ� cur�� ���� ���� ��带 ����

		free(tmp); // �����Ϸ��� ���� �޸𸮸� ������Ų��
		singleList2.length-- // ���� �� ����Ʈ ���� ����
		return 1; //Success
}

int singleList2::insertAfter(int index, Node* target){
    if (index>singleList2.length || index<0){
            cout<<"Out of Range"<<endl;
            return 1; //ERROR
    }
    else if(singleList2.length == 0 ){
        Node* node = Node::create(NULL);
        return 1; //ERROR
    }
        Node *cur=singleList2.getNode(index); //index���� ���

        target -> next= cur->next; // ���� ��尡 ������ �ִ� ������ �޾ƿ�
        cur ->next=target; // ���� ��� -> ���� ��� -> ���� ���
        singleList2.length++;
        return 0; //SUCCESS
}

int singleList2::display() {
    if(this->head == NULL) { // �� ����Ʈ��
        cout << "Empty List!" << endl; //ǥ���ϰ�
        return 1; //�Լ� ����
    }
    Node* current = this->head; //�󸮽�Ʈ�� �ƴϸ� ��� ���� ����
    cout << "LinkedList: "; // ǥ�� ����
    while(current != NULL) { // ������ ���鼭
       cout << current->data << " \n"; // �Լ� ������ ���
       current = current->nextNode; // ���� ���� �̵�
    }
    cout << "END" << endl;
    return 0; //Success
}

int singleList2::getLength() { // ����Ʈ �� ���� ����(���Ұ������)

    return singleList2.length; //���� ����
}

singleList2:singleList2() {
    this->head = NULL; //��� �η� �ʱ�ȭ
};

int main() {
    cout<<"Testing"<<endl;
    Node* test_node_1 = Node::create(10);
    singleList2.display();

}
