#define SUCCESS 0
#define ERROR 1

#ifndef Node_H //Node class�� ���ǵǾ� ���� �ʴٸ�
#define Node_H //Node ����
class Node{
    public:
            int data; //Node�� ����Ǵ� ������
            Node* nextNode=nullptr; // ���� ��带 ����Ű�� ������
            Node* create(int data); // �Է� ���� ���� ��� ����
            void deleteNode(Node *node); //�Էµ� ��带 ����
};
#endif // ���� ��

#ifndef singleList2_H //singleList2�� ���ǵ��� �ʾҴٸ�
#define singleList2_H // singleList2�� �����Ѵ�.
class singleList2 {
    private:
        static int length; //list ��ü ����
    public:
        static Node* head; //list ���� ��带 ����Ų��
        int setHead(Node* node); // Head���� ����
        int appendNode(Node* node); // ��带 ����Ʈ ���� �߰��Ѵ�.
        Node* getNode(int index); // �ε����� �ش��ϴ� ��带 �����Ѵ�.
        int removeNode(int index); // �ε����� �ش��ϴ� ��带 �����Ѵ�.
        int insertAfter(int index, Node* target);// �ε��� ��ġ�� target��带 �߰��Ѵ�.
        int display(); // ����Ʈ�� ����Ѵ�.
        int getLength(); //����Ʈ ��ü ���̸� �����Ѵ�.
        int init(); // ����Ʈ�� ���� �� �ʱ�ȭ�Ѵ�.
};
#endif






