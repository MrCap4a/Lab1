#include <iostream>
#include <string>
using namespace std;

//Даны две непустые очереди; адреса начала и конца первой равны P1 и P2, а второй —    P3   и P4.   Элементы   каждой   из очередей    упорядочены по возрастанию (в направлении от начала очереди к концу). Объединить очереди в одну с сохранением упорядоченности элементов. Вывести указатели на начало и конец полученной очереди. Операции выделения
//и освобождения   памяти   не использовать, поля    с    данными(Data) не изменять.


struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

Queue merge(Queue queue1, Queue queue2) {
    Queue Queues;
    Node t;
    Node* current = &t;
    Node* temp1 = queue1.front;
    Node* temp2 = queue2.front;

    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->data <= temp2->data) {
            current->next = temp1;
            temp1 = temp1->next;
        }
        else {
            current->next = temp2;
            temp2 = temp2->next;
        }
        current = current->next;
    }

    if (temp1 != nullptr) {
        current->next = temp1;
    }
    else {
        current->next = temp2;
    }

    Queues.front = t.next;

    current = Queues.front;
    while (current->next != nullptr) {
        current = current->next;
    }
    Queues.rear = current;

    return Queues;
}

int main() {
    setlocale(LC_ALL, "Russian");

    Queue queue1;
    Node* p1 = new Node{ 1, nullptr };
    Node* p2 = new Node{ 3, nullptr };
    Node* p3 = new Node{ 5, nullptr };
    Node* p4 = new Node{ 7, nullptr };
    queue1.front = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    queue1.rear = p4;

    Queue queue2;
    Node* p5 = new Node{ 2, nullptr };
    Node* p6 = new Node{ 4, nullptr };
    Node* p7 = new Node{ 6, nullptr };
    Node* p8 = new Node{ 8, nullptr };
    queue2.front = p5;
    p5->next = p6;
    p6->next = p7;
    p7->next = p8;
    queue2.rear = p8;

    Queue Queues = merge(queue1, queue2);

    cout << "Указатель на начало объединенной очереди: " << Queues.front << endl;
    cout << "Указатель на конец объединенной очереди: " << Queues.rear << endl;

    return 0;
}