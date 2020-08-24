#ifndef CIRCLE2_H_INCLUDED
#define CIRCLE2_H_INCLUDED
#define SUCCESS 1
#define ERROR 0

class Node{
public:
    int data;
    Node* nextNode=nullptr;
};

class Circle{
private:
    int length=0;
public:
    void init();
    Node* head;
    Node* createNode(int input);
    int setHead(Node* targetNode);
    int insertNode(int index,Node* targetNode);
    int deleteNode(int index);
    int appendNode(Node* targetNode);
    Node* getNode(int index);
    int display();
    int getLength();
};







#endif // CIRCLE2_H_INCLUDED
