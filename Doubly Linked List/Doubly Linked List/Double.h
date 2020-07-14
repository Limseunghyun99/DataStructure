#ifndef DOUBLE_H_INCLUDED
#define DOUBLE_H_INCLUDED
#define SUCCESS 0
#define ERROR 1


class Node{
public:
        int data;
        Node* nextNode;
        Node* preNode;
};
class DoublyLinkedList{
private:
    int length=0;

public:
    Node* head;
    Node* createNode(int input);
    int setHead(Node* target);
    Node* getNode(int index);
    int insertNode(int index, Node* target);
    int removeNode(int index);
    int appendNode(Node* target);
    int getLength();
    int display();
};
#endif // DOUBLE_H_INCLUDED
