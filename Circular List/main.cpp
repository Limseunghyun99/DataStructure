#include <iostream>
#include "circle2.h"

using namespace std;

void Circle::init(){
    this->head = nullptr;
    this->length = 0;
}

Node* Circle::createNode(int input){
    Node* tmp = new Node;
    tmp->data = input;
    tmp->nextNode = nullptr;
    return tmp;
}

int Circle::display(){
    if (this->head == nullptr){
        cout<<"This list is empty! from display!\n"<<endl;
    }
    else{
        Node* tmp;
        tmp = this->head;
        for (int i=0; i<this->length;i++){
            cout<<i+1<<"번째 노드 : "<<tmp->data<<"\n"<<endl;
            if(tmp->nextNode == nullptr){
                cout<<"Finished!!\n\n"<<endl;
                break;
            }
            tmp=tmp->nextNode;
        }
        return SUCCESS;
    }
}

int Circle::setHead(Node* targetNode){
    if(this->head == nullptr){
        this->head = targetNode;
        this->length++;
        return SUCCESS;
    }
    else{
        targetNode->nextNode = this->head;
        this->head = targetNode;
        this->length++;
        return SUCCESS;
    }
}

int Circle::appendNode(Node* targetNode){
    cout<<"Append Node is started"<<endl;
    if(this->head == nullptr){
        cout<<"This list is empty! Please set Head First from appendNode"<<endl;
        this->head=targetNode;
        this->length++;
        return ERROR;
    }
    else if(this->length==1){
        this->head->nextNode = targetNode;
        this->length++;
        return SUCCESS;
    }
    else{
        Node* tmp=this->head;
        for(int i=1;i<this->length;i++){
            tmp=tmp->nextNode;
        }
        tmp->nextNode = targetNode;
        this->length++;
        return SUCCESS;
    }

}

int Circle::deleteNode(int index){
    if(this->head == nullptr){
        cout<<"This list is empty! Please Set Head first from deleteNode"<<endl;
        return ERROR;
    }
    else if (index <0 || index > this->length){
        cout<<"Out of Range from delete Node"<<endl;
        return ERROR;
    }
    else{
        Node* tmp= this->head;
        for(int i=1;i<index;i++){
            tmp=tmp->nextNode;
        }
        tmp->nextNode = tmp->nextNode->nextNode;
        this->length--;
    }

}

Node* Circle::getNode(int index){
    if(this->head == nullptr){
        cout<<"This list is empty! Please Set Head first from getNode"<<endl;
        return nullptr;
    }
    else if (index <0 || index > this->length){
        cout<<"Out of Range from getNode"<<endl;
        return nullptr;
    }
    else{
        Node* tmp= this->head;
        for(int i=0;i<index;i++){
            tmp=tmp->nextNode;
        }
        return tmp;
    }



}


int Circle::insertNode(int index,Node* targetNode){
    if(this->head == nullptr){
        cout<<"This list is empty! Please Set Head first from insertNode"<<endl;
        return ERROR;
    }
    else if (index <0 || index > this->length){
        cout<<"Out of Range from insertNode"<<endl;
        return ERROR;
    }
    else{
        Node* tmp= this->head;
        for(int i=1;i<index;i++){
            tmp=tmp->nextNode;
        }
        targetNode->nextNode = tmp->nextNode;
        tmp->nextNode= tmp->nextNode->nextNode;
        this->length++;
    }

}


int main()
{
    Circle test;
    test.init();
    Node* alpha = test.createNode(1);
    Node* beta= test.createNode(2);
    Node* chicken= test.createNode(10);
    Node* pringles= test.createNode(21);
    cout<<"Create Node is finished"<<endl;
    test.setHead(alpha);
    cout<<"Set Head is finished"<<endl;
    test.appendNode(beta);
    test.appendNode(chicken);
    test.appendNode(pringles);

    test.display();

    return 0;
}
