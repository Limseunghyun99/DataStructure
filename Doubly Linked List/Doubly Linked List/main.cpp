#include <iostream>
#include "Double.h"

using namespace std;

Node* DoublyLinkedList::createNode(int input)
{
    Node* tmp = new Node;;                                          //�ӽ÷� ��� ����
    tmp->data = input;                                              //�Է°��� �����ͷ� ����
    tmp->nextNode = nullptr;                                       //���� �����͸� null�� ����
    tmp->preNode = nullptr;                                        //���� �����͸� null�� ����
    return tmp;
}

int DoublyLinkedList::setHead(Node* target)
{
    if (this->length == 0)                                   // ���̰� 0�̸�
    {
       this->head = target;                                  //��� ����
       return ERROR;
    }
    else if (this -> head == nullptr)
    {
        this->head = target;
    }
    else                                                          // �̹� ��尡 �����ϸ�
    {
    target->nextNode = this->head;                          //�Է� -> ���� ���
    this->head->preNode = target;                           //�Է� <- �������
    this->head = target;                                    // �� ��� <=> ���� ���
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
    if(this->head == nullptr)                               // ��尡 null
    {
        cout<<"Head is null,appendNode\n"<<endl;
        this->head = target;                                 //���� ����
        this->length++;                                      // ���� �߰�
        return ERROR;                                             //����
    }
    else
    {
        Node* tmp = this->head;                              // ��忡 ����
        while(tmp->nextNode != nullptr)                           // ������
        {
            tmp= tmp->nextNode;
                                                                   // �̵�
        }
        tmp->nextNode=target;                                      // �� �ڿ� �Է� ��� ����
        target->preNode = tmp;                                     // ���� ���� ����
        this->length++;                                      // ���� �߰�
    return SUCCESS;
}
}

Node* DoublyLinkedList::getNode(int index)
{
    Node* tmp = this->head;                                  //��� ����
    if (this->head == nullptr){                             // ��尡 null�̸�
        std::cout<<"Head is null"<<endl;
        return nullptr;                         // �������
    }
    else if(this->length <index)                            // �ε����� ���̺��� ���
    {
        std::cout<<"Index is out of range"<<endl;
        return nullptr;                 //���� ���
    }
    else{
        for(int i=0;i<index;i++)                                  // index��ŭ �̵�
        {
            tmp=tmp->nextNode;                                     //�̵�
        }
    }
    return tmp;                                                   //��� ����
}

int DoublyLinkedList::insertNode(int index, Node* target)
{
    if (this->head == nullptr)                               //��尡 null
    {
        std::cout<<"Head is null"<<endl;                           //�޼���
        this->head = target;                                  // �Է� ��带 ����
        this->length++;                                       // ���� �߰�
        return ERROR;
    }
    else if(this->length <index)                             // �ε����� ���̺��� ���
    {
        std::cout<<"Index is out of range"<<endl;                  //���� ���
        return ERROR;
    }
    else{
        Node* tmp=this->head;                                 //��� ����
        for (int i=0;i<index;i++)                                  // �ε��� ��ŭ
        {
            tmp=tmp->nextNode;                                      // �̵�
        }
        target->preNode = tmp->preNode;
        target->nextNode = tmp;
        tmp->preNode->nextNode = target;
        tmp->preNode = target;
        this->length++;                                       // ���� �߰�
    }
    return SUCCESS;

}

int DoublyLinkedList::removeNode(int index)
{
    if (this->head == nullptr){
        std::cout<<"Head is null"<<endl;
        return ERROR;
    }
    else if(this->length <index)                              // �ε����� ���̺��� ���
    {
        std::cout<<"Index is out of range"<<endl;                  //���� ���
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
        for (int i=0;i<index;i++)                                  //�ε�����ŭ �̵�
        {
            tmp = tmp->nextNode;                                    //�̵�
        }
        tmp->preNode->nextNode = nullptr
        free(tmp)
        return ERROR;
    }
    else{
        Node* tmp=this->head;
        for (int i=0;i<index;i++)                                  //�ε�����ŭ �̵�
        {
            tmp = tmp->nextNode;                                    //�̵�
        }
        tmp->preNode->nextNode = tmp->nextNode;                     //���� ��带 ���� ��忡 ����
        tmp->nextNode->preNode = tmp->preNode;                      // ���� ��带 ���� ��忡 ����
        free(tmp);                                                  // �޸� ����
        this->length--;                                       // ���� ����
    }
    return SUCCESS;
}

int DoublyLinkedList::display()
{
    if (this->head == nullptr){                              // �� ����Ʈ��
        cout << "Empty List!" << endl;                             //ǥ���ϰ�
        return ERROR;                                              //�Լ� ����
    }
    Node* current = this->head;                               //�󸮽�Ʈ�� �ƴϸ� ��� ���� ����
    cout << "Doubly Linked List: \n"<<endl;                        // ǥ�� ����
    while(current->nextNode != nullptr)
    {
    cout << current->data << " \n"<<endl;;                         // �Լ� ������ ���
    current = current->nextNode;                                    // ���� ���� �̵�
    }
    cout << "Last Node: "<<current->data << " \n"<<endl;;          // �Լ� ������ ���

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
