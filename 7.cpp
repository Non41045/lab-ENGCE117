#include <stdio.h>

class Node {
public:
    int Data;
    Node *Next;
    Node *Back;
    Node(int data = 0) : Data(data), Next(NULL), Back(NULL) {}
};

class DoubleLinkedList : Node {
private:
    Node *head;
public:
    DoubleLinkedList() : head(NULL) {}
    void AddNode();
    void InsertNode();
    void DeleteNode();
    void ShowFront();
    void ShowBack();
};

int main() {
    DoubleLinkedList A, B;
    A.AddNode(); A.AddNode(); A.ShowFront();
    A.InsertNode(); A.InsertNode(); A.ShowFront();
    A.DeleteNode(); A.DeleteNode(); A.ShowFront();
    printf( "---\n" );
    B.AddNode(); B.AddNode(); B.AddNode(); B.ShowBack();
    return 0;
}

void DoubleLinkedList :: ShowBack() {
    Node *temp = head;
    if (!temp) return;
    while (temp->Next) temp = temp->Next;
    while (temp) {
        printf("%d ", temp->Data);
        temp = temp->Back;
    }
    printf("\n");
}

void DoubleLinkedList :: ShowFront() {
    Node *temp = head;
    while (temp) {
        printf("%d ", temp->Data);
        temp = temp->Next;
    }
    printf("\n");
}

void DoubleLinkedList :: DeleteNode() {
    if (!head) return;
    Node *temp = head;
    head = head->Next;
    if (head) head->Back = NULL;
    delete temp;
}

void DoubleLinkedList :: InsertNode() {
    int data, pos;
    printf("Insert (data pos) : ");
    scanf("%d %d", &data, &pos);
    Node *newNode = new Node(data);
    if (pos <= 1 || !head) {
        newNode->Next = head;
        if (head) head->Back = newNode;
        head = newNode;
        return;
    }
    Node *temp = head;
    int count = 1;
    while (temp->Next && count < pos - 1) {
        temp = temp->Next;
        count++;
    }
    newNode->Next = temp->Next;
    newNode->Back = temp;
    if (temp->Next) temp->Next->Back = newNode;
    temp->Next = newNode;
}

void DoubleLinkedList :: AddNode() {
    int data;
    printf("Add (data) : ");
    scanf("%d", &data);
    Node *newNode = new Node(data);
    if (!head) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->Next) temp = temp->Next;
        temp->Next = newNode;
        newNode->Back = temp;
    }
}