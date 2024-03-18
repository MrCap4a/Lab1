#include <iostream>
using namespace std;

//2.	Создать линейный двунаправленный список из целых чисел. Вставить в список число 11 после каждого элемента, равного 9.

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void insert(Node*& head, Node*& tail, int value) {
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

void insertAfterNine(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == 9) {
            Node* newNode = new Node();
            newNode->data = 11;
            newNode->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            newNode->prev = current;
            current = newNode->next;
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

    insert(head, tail, 9);
    insert(head, tail, 5);
    insert(head, tail, 9);
    insert(head, tail, 3);

    cout << "До вставки 11: ";
    printList(head);

    insertAfterNine(head);

    cout << "После вставки 11: ";
    printList(head);

    return 0;
}