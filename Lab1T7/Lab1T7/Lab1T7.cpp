#include <iostream>
#include <string>
using namespace std;

//2.	Создать линейный однонаправленный список строк. Удалить строку с минимальной длиной.

struct Node {
    string data;
    Node* next;
};

void insertNode(Node*& head, string value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteMinLengthNode(Node*& head) {
    if (head == nullptr) {
        return;
    }

    Node* minNode = head;
    Node* prevNode = nullptr;
    Node* current = head;

    while (current != nullptr) {
        if (current->data.length() < minNode->data.length()) {
            minNode = current;
            prevNode = current->next;
        }
        else if (prevNode != nullptr) {
            prevNode->next = current->next;
        }
        current = current->next;
    }

    if (minNode == head) {
        head = head->next;
    }
    delete minNode;
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

    int n;
    cout << "Введите количество строк: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string value;
        cout << "Введите строку " << i + 1 << ": ";
        cin >> value;
        insertNode(head, value);
    }

    deleteMinLengthNode(head);

    cout << "Список после удаления строки с минимальной длиной: ";
    printList(head);

    return 0;
}