#include <iostream>
#include <string>
#include <vector>

//1.	Создать стек из целых чисел.Вычислить произведение нечётных значений элементов стека.Организовать просмотр данных стека.

using namespace std;

vector <int> st;
int sm = 1;

void push(int el) {
    st.push_back(el);
    if (el % 2 == 1) {
        sm *= el;
    }
}

int top() {
    return st.back();
}

void pop() {
    if (top() % 2 == 1) {
        sm /= top();
    }
    st.pop_back();
}

int get_size() {
    return st.size();
}

void print() {
    int size = get_size();
    for (int i = 1; i <= size; i++) {
        cout << st[size - i] << " ";
    }
}

void get() {
    if (sm != 1) {
        cout << sm << endl;
    }
    else {
        cout << 0 << endl;
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print();
    cout << endl << top();
    pop();
    cout << endl << top() << endl;
    print();
    cout << endl;
    get();
}