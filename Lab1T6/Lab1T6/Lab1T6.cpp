#include <iostream>
#include <string>
using namespace std;

//1.	Создать линейный однонаправленный список из целых чисел. Определить среднее арифметическое значений элементов списка, кратных 4.

struct Node {
    int data;
    Node* next;
};

float findAverage(Node* head) {
    int sum = 0;
    int count = 0;

    Node* current = head;
    while (current != nullptr) {
        if (current->data % 4 == 0) {
            sum += current->data;
            count++;
        }
        current = current->next;
    }

    if (count > 0) {
        return (sum / count);
    }
    else {
        return 0;
    }
}

void insertNode(Node*& head, int value) {
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

int main() {
    setlocale(LC_ALL, "Ru");

    Node* head = nullptr;

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Введите значение элемента " << i + 1 << ": ";
        cin >> value;
        insertNode(head, value);
    }

    float average = findAverage(head);
    cout << "Среднее арифметическое значений элементов, кратных 4: " << average << endl;

    return 0;
}