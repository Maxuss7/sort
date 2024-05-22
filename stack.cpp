#include "stack.h"
#include <iostream>
using namespace std;

MyLinkedListStack::MyLinkedListStack() : top(nullptr), N_op(0) {}

MyLinkedListStack::~MyLinkedListStack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

void MyLinkedListStack::Add(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    N_op++;
}

bool MyLinkedListStack::IsEmpty() {
    return top == nullptr;
}

int MyLinkedListStack::Length() {
    int count = 0;
    Node* current = top;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

int MyLinkedListStack::Del() {
    int val = 0;
    if (!IsEmpty()) {
        val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        N_op++;
    } else {
        cout << "Стек пуст" << endl;
    }
    return val;
}

int MyLinkedListStack::Value() {
    if (!IsEmpty()) {
        return top->data;
    } else {
        cout << "Стек пуст" << endl;
        return 0;
    }
}

void MyLinkedListStack::Print() {
    if (!IsEmpty()) {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    } else {
        cout << "Стек пуст" << endl;
    }
}

vector<int> MyLinkedListStack::ToArray() {
    std::vector<int> result;
    Node* current = top;
    while (current != nullptr) {
        result.push_back(current->data);
        current = current->next;
    }
    return result;
}

int Numbers::Get(int pos) {
    MyLinkedListStack tempStack;
    int value = -1;
    for (int i = 0; i <= pos && !IsEmpty(); ++i) {
        value = Del();
        tempStack.Add(value);
    }
    while (!tempStack.IsEmpty()) {
        Add(tempStack.Del());
    }
    return value;
}

void Numbers::Set(int pos, int number) {
    MyLinkedListStack tempStack;
    for (int i = 0; i < pos && !IsEmpty(); ++i) {
        tempStack.Add(Del());
    }
    if (!IsEmpty()) {
        Del();
        Add(number);
    }
    while (!tempStack.IsEmpty()) {
        Add(tempStack.Del());
    }
}

void Numbers::Sort(int N) {
    MyLinkedListStack tempStack;
    
    // Найти минимальное и максимальное значение в стеке
    int minVal = Value(); // Первый элемент в стеке
    int maxVal = minVal;
    while (!IsEmpty()) {
        int value = Del();
        if (value < minVal) minVal = value;
        if (value > maxVal) maxVal = value;
        tempStack.Add(value);
    }
    
    // Создаем массив счетчиков
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);
    
    // Заполнить массив счетчиков
    while (!tempStack.IsEmpty()) {
        int value = tempStack.Del();
        count[value - minVal]++;
    }
    
    // Добавить элементы обратно в отсортированном порядке
    for (int i = range - 1; i >= 0; --i) {
        while (count[i]-- > 0) {
            Add(i + minVal);
        }
    }
}
