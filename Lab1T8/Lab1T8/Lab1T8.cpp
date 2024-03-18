#include <iostream>
using namespace std;

//1.	Создать линейный однонаправленный список из вещественных чисел. Удалить из списка элемент перед каждым элементом со значением 55.

struct Node {
    double data;
    Node* next;
};

void insertNode(Node*& head, double value) {
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

void deleteBefore55(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current->next != nullptr) {
        if (current->next->data == 55) {
            Node* deletedNode = previous != nullptr ? previous->next : head;
            if (previous != nullptr) {
                previous->next = current->next;
            }
            else {
                head = current->next;
            }
            current = current->next;
            delete deletedNode;
        }
        else {
            previous = current;
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

    int n;
    cout << "Введите количество чисел: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        double value;
        cout << "Введите число " << i + 1 << ": ";
        cin >> value;
        insertNode(head, value);
    }

    deleteBefore55(head);

    cout << "Список после удаления элементов перед 55: ";
    printList(head);

    return 0;
}