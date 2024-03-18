#include <iostream>
#include <string>
#include <vector>

//2.	Создать стек, информационными полями которого являются: монитор, диагональ и его цена. Добавить в стек сведения о новом мониторе. 
// Организовать просмотр данных стека и определить количество мониторов с диагональю более 20 дюймов.

using namespace std;

struct monitor {
    string name;
    float diagonal;
    int price;
};

vector <monitor> st;
int diagonals = 0;

void push(string name, float diagonal, int price) {
    st.push_back({name, diagonal, price});
    if (diagonal > 20) {
        diagonals += 1;
    }
}

monitor top() {
    return st.back();
}

void pop() {
    if (top().diagonal > 20) {
        diagonals -= 1;
    }
    st.pop_back();
}

int get_size() {
    return st.size();
}

void print() {
    int size = get_size();
    for (int i = 1; i <= size; i++) {
        cout << st[size - i].name << ", diagonal: " << st[size - i].diagonal << ", price: " << st[size - i].price << ".\n";
    }
}

void get() {
    cout << diagonals;
}

int main()
{
    push( "Lg", 15.6, 200 );
    push( "samsung", 20, 240);
    push( "xiaomi", 24, 240);
    push( "msi", 22, 280);
    print();
    cout << endl;
    cout << top().name << ", diagonal: " << top().diagonal << ", price: " << top().price << "." << endl;
    cout << endl;
    pop();
    cout << top().name << ", diagonal: " << top().diagonal << ", price: " << top().price << "." << endl;
    cout << endl;
    print();
    cout << endl;
    get();
}
