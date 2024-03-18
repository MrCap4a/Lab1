#include <iostream>
using namespace std;

//Создать циклический двунаправленный список из вещественных чисел.
//Удалить из списка элемент перед каждым элементом со значением 3.


struct Node {
    double data;
    Node* prev;
    Node* next;
};

void insert(Node*& head, Node*& tail, double value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
}

void deleteBeforeThree(Node*& head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == 3) {
            Node* nodeToDelete = current;
            current = current->next;
            if (nodeToDelete->prev != nullptr) {
                nodeToDelete->prev->next = current;
            }
            if (current != nullptr) {
                current->prev = nodeToDelete->prev;
            }
            if (nodeToDelete == head) {
                head = current;
            }
            delete nodeToDelete;
        }
        else {
            current = current->next;
        }
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");

    Node* head = nullptr;
    Node* tail = nullptr;

    insert(head, tail, 1.5);
    insert(head, tail, 3.0);
    insert(head, tail, 2.7);
    insert(head, tail, 5.2);
    insert(head, tail, 3.0);
    insert(head, tail, 4.8);

    cout << "До удаления элементов перед 3: ";
    printList(head);

    deleteBeforeThree(head);

    cout << "После удаления элементов перед тройкой 3: ";
    printList(head);

    return 0;
}