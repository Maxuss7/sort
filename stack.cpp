#include "stack.h"
#include <vector>
#include <iostream>
using namespace std;

MyLinkedListStack::MyLinkedListStack() {
    top = nullptr; // 1
}

MyLinkedListStack::~MyLinkedListStack() {
    while (top != nullptr) {            // 2 +
        Node* temp = top;               // 1
        top = top->next;                // 1
        delete temp;                    // 1
    }
}

void MyLinkedListStack::Add(int x) {    // 5
    Node* newNode = new Node;           // 1
    newNode->data = x;                  // 1
    newNode->next = top;                // 1
    top = newNode;                      // 1
}

bool MyLinkedListStack::IsEmpty() {     // 2
    return top == nullptr;              // 2
}

int MyLinkedListStack::Length() {
    int count = 0;                      // 1
    Node* current = top;                // 1
    while (current != nullptr) {        // 2 +
        count++;                        // 1
        current = current->next;        // 1
    }
    return count;                       // 1
}

int MyLinkedListStack::Del() {          // 11
    int val = 0;                        // 1
    if (!IsEmpty()) {                   // 4
        val = top->data;                // 1
        Node* temp = top;               // 1
        top = top->next;                // 1
        delete temp;                    // 1
    } else {
        cout << "Стек пуст" << endl;    // 1
    }
    return val; // 1
}

int MyLinkedListStack::Value() {        // 7
    if (!IsEmpty()) {                   // 4
        return top->data;               // 1
    } else {
        cout << "Стек пуст" << endl;    // 1
        return 0;                       // 1
    }
}

void MyLinkedListStack::Print() { 
    if (!IsEmpty()) { // 4
        Node* current = top; // 1
        while (current != nullptr) {    // 2 +
            cout << current->data << " "; // 1
            current = current->next;    // 1
        }
        cout << endl;                   // 1
    } else {
        cout << "Стек пуст" << endl;    // 1
    }
}

int Numbers::Get(int pos) {             // 1 +
    MyLinkedListStack tempStack;        // 1
    int value = -1;                     // 1
    for (int i = 0; i <= pos && !IsEmpty(); ++i) { // 6
        value = Del();                  // 11
        tempStack.Add(value);           // 5
    }
    while (!tempStack.IsEmpty()) {      // 4
        Add(tempStack.Del());           // 16
    }
    return value;                       // 1
}

void Numbers::Set(int pos, int number) { // 2 +
    MyLinkedListStack tempStack;         // 1
    for (int i = 0; i < pos && !IsEmpty(); ++i) { // 6 + 
        tempStack.Add(Del());           // 16
    }
    if (!IsEmpty()) {                   // 4
        Del();                          // 11
        Add(number);                    // 5
    }
    while (!tempStack.IsEmpty()) {      // 4 +
        Add(tempStack.Del());           // 16
    }
}

void Numbers::Sort(int n) {             // 1 +
    /*
    В оригинальной "сортировке подсчетом" ищутся мин и макс
    числа, и создается массив счетчиков, длина которого равна разнице мин и макс
    значений массива.
    Однако, из-за этой неопределенности мы НЕ МОЖЕМ НАЙТИ ПОЛИНОМ ИСПОЛЬЗУЯ ТОЛЬКО N.
    Придется самому выставить минимальное и максимальное значение, что очень плохо
    повлияет на логику программы. Ведь реальные макс и мин значения могут уйти за границы.
    Также, мне придется сделать очень малький мин и большой макс, что повлияет и на скорость.
    Массив счетчиков будет длинным и в основном заполнен нулями. Но другого пути нет, 
    думал над этой проблемой часами и уже хочу разбить экран.

   
    int minVal = Value(); // 7
    int maxVal = minVal; // 1
    while (!IsEmpty()) { // 4 + 
        int value = Del(); // 12
        if (value < minVal) minVal = value; // 3
        if (value > maxVal) maxVal = value; // 3
        tempStack.Add(value); // 5
    }
    и тд
    */
    MyLinkedListStack tempStack;        // 1
    
    // Константы для минимального и максимального значений
    const int MIN_VAL = -1000;          // 1
    const int MAX_VAL = 1000;           // 1

    // Заполняем временный стек данными до сортировки
    while (!IsEmpty()) {                // 3 +               
        int value = Del();              // 12
        if (value < MIN_VAL || value > MAX_VAL) { // 4
            cerr << "Out of range value found." << endl; // 1
            return;                                      // 1
        }
        tempStack.Add(value);                            // 15
    }

    // Создаем временный стек для счетчиков
    // Но придется сделать ноду публичной
    MyLinkedListStack countStack;                       // 1

    // Заполняем временный стек счетчиков
    for (int i = MIN_VAL; i <= MAX_VAL; ++i) {
        int count = 0;                                  // 1
        // Считаем количество элементов с данным значением
        MyLinkedListStack::Node* current = tempStack.top; // 1
        while (current != nullptr) {                      // 2
            if (current->data == i)                       // 2
                count++;                                  // 1
            current = current->next;                      // 1
        }

        countStack.Add(count);                            // 5
    }

    // Добавляем элементы обратно в отсортированном порядке (с конца)
    for (int i = MAX_VAL; i >= MIN_VAL; --i) {
        MyLinkedListStack::Node* current = tempStack.top; 
        while (current != nullptr) {
            if (current->data == i) {
                Add(i);
                countStack.top->data--;
                if (countStack.top->data == 0)
                    countStack.Del();
            }
            current = current->next;
        }
    }
}
















































































