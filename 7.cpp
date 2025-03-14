#include <stdio.h>

class Node {
    public:
        int Data;
        Node *Next;
        Node *Back;
    public:
        Node(int data = 0) : Data(data), Next(NULL), Back(NULL) {}
};

class DoubleLinkedList : public Node {  // ใช้ public inheritance
    private:
        Node *head;
        Node *tail;  // เพิ่ม tail เพื่อทำให้สามารถเข้าถึงท้ายได้ง่าย
    public:
        DoubleLinkedList() : head(NULL), tail(NULL) {}
        void AddNode(int data);
        void InsertNode(int data, int pos);
        void DeleteNode(int pos);
        void ShowFront();
        void ShowBack();
};

int main() {
    DoubleLinkedList A, B;
    int data, pos;

    // กรอกข้อมูลและดำเนินการกับ DoubleLinkedList A
    printf("Add (data): ");
    scanf("%d", &data);
    A.AddNode(data);

    printf("Add (data): ");
    scanf("%d", &data);
    A.AddNode(data);
    A.ShowFront();

    // การแทรกข้อมูล
    printf("Insert (data pos): ");
    scanf("%d %d", &data, &pos);
    A.InsertNode(data, pos);
    A.ShowFront();

    // การลบข้อมูล
    printf("Delete (pos): ");
    scanf("%d", &pos);
    A.DeleteNode(pos);
    A.ShowFront();

    printf("---\n");

    // กรอกข้อมูลและดำเนินการกับ DoubleLinkedList B
    printf("Add (data): ");
    scanf("%d", &data);
    B.AddNode(data);

    printf("Add (data): ");
    scanf("%d", &data);
    B.AddNode(data);

    printf("Add (data): ");
    scanf("%d", &data);
    B.AddNode(data);

    B.ShowBack();

    return 0;
}

void DoubleLinkedList::ShowFront() {
    Node* current = head;
    printf("Show Front : ");
    while (current != NULL) {
        printf("%d ", current->Data);
        current = current->Next;
    }
    printf("\n");
}

void DoubleLinkedList::ShowBack() {
    Node* current = tail;
    printf("Show Back : ");
    while (current != NULL) {
        printf("%d ", current->Data);
        current = current->Back;
    }
    printf("\n");
}

void DoubleLinkedList::DeleteNode(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* current = head;
    int index = 1;

    // หา node ที่ต้องการลบ
    while (current != NULL && index < pos) {
        current = current->Next;
        index++;
    }

    // ถ้าตำแหน่งไม่ถูกต้อง
    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }

    // ถ้าคือ node แรก
    if (current == head) {
        head = current->Next;
        if (head != NULL) {
            head->Back = NULL;
        }
    }
    // ถ้าคือ node สุดท้าย
    else if (current == tail) {
        tail = current->Back;
        if (tail != NULL) {
            tail->Next = NULL;
        }
    }
    // ลบ node ปกติ
    else {
        current->Back->Next = current->Next;
        if (current->Next != NULL) {
            current->Next->Back = current->Back;
        }
    }

    delete current;
}

void DoubleLinkedList::InsertNode(int data, int pos) {
    Node* newNode = new Node(data);
    if (head == NULL || pos == 1) {
        newNode->Next = head;
        if (head != NULL) {
            head->Back = newNode;
        }
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
        return;
    }

    Node* current = head;
    int index = 1;
    while (current != NULL && index < pos - 1) {
        current = current->Next;
        index++;
    }

    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->Next = current->Next;
    if (current->Next != NULL) {
        current->Next->Back = newNode;
    }
    current->Next = newNode;
    newNode->Back = current;

    // ถ้าแทรกที่ท้าย
    if (newNode->Next == NULL) {
        tail = newNode;
    }
}

void DoubleLinkedList::AddNode(int data) {
    Node* newNode = new Node(data);

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->Next = newNode;
        newNode->Back = tail;
        tail = newNode;
    }
}
