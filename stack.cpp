#include "stack.h"
#include <iostream>
using namespace std;

MyLinkedListStack::MyLinkedListStack() {
    top = nullptr; // 1
}

MyLinkedListStack::~MyLinkedListStack() {
    while (top != nullptr) { // 2 +
        Node* temp = top; // 1
        top = top->next; // 1
        delete temp; // 1
    }
}

void MyLinkedListStack::Add(int x) { // 5
    Node* newNode = new Node; // 1
    newNode->data = x; // 1
    newNode->next = top; // 1
    top = newNode; // 1
}

bool MyLinkedListStack::IsEmpty() { // 2
    return top == nullptr; // 2
}

int MyLinkedListStack::Length() {
    int count = 0; // 1
    Node* current = top; // 1
    while (current != nullptr) { // 2 +
        count++; // 1
        current = current->next; // 1
    }
    return count; // 1
}

int MyLinkedListStack::Del() { // 11
    int val = 0; // 1
    if (!IsEmpty()) { // 4
        val = top->data; // 1
        Node* temp = top; // 1
        top = top->next; // 1
        delete temp; // 1
    } else {
        cout << "Стек пуст" << endl; // 1
    }
    return val; // 1
}

int MyLinkedListStack::Value() { // 7
    if (!IsEmpty()) { // 4
        return top->data; // 1
    } else {
        cout << "Стек пуст" << endl; // 1
        return 0; // 1
    }
}

void MyLinkedListStack::Print() { 
    if (!IsEmpty()) { // 4
        Node* current = top; // 1
        while (current != nullptr) { // 2 +
            cout << current->data << " "; // 1
            current = current->next; // 1
        }
        cout << endl; // 1
    } else {
        cout << "Стек пуст" << endl; // 1
    }
}

int Numbers::Get(int pos) { // 1 +
    MyLinkedListStack tempStack; // 1
    int value = -1; // 1
    for (int i = 0; i <= pos && !IsEmpty(); ++i) { // 6
        value = Del(); // 11
        tempStack.Add(value); // 5
    }
    while (!tempStack.IsEmpty()) { // 4
        Add(tempStack.Del()); // 16
    }
    return value; // 1
}

void Numbers::Set(int pos, int number) { // 2 +
    MyLinkedListStack tempStack; // 1
    for (int i = 0; i < pos && !IsEmpty(); ++i) { // 6 + 
        tempStack.Add(Del()); // 16
    }
    if (!IsEmpty()) { // 4
        Del(); // 11
        Add(number); // 5
    }
    while (!tempStack.IsEmpty()) { // 4 +
        Add(tempStack.Del()); // 16
    }
}

void Numbers::Sort(int N) { // 1 + 
    MyLinkedListStack tempStack; // 1
    
    // Найти минимальное и максимальное значение в стеке
    int minVal = Value(); // 7
    int maxVal = minVal; // 1
    while (!IsEmpty()) { // 4 + 
        int value = Del(); // 12
        if (value < minVal) minVal = value; // 3
        if (value > maxVal) maxVal = value; // 3
        tempStack.Add(value); // 5
    }
    
    // Создаем массив счетчиков
    int range = maxVal - minVal + 1; // 3
    vector<int> count(range, 0); // 1
    
    // Заполнить массив счетчиков
    while (!tempStack.IsEmpty()) { // 4
        int value = tempStack.Del(); // 12
        count[value - minVal]++; // 3
    }
    
    // Добавить элементы обратно в отсортированном порядке
    for (int i = range - 1; i >= 0; --i) {
        while (count[i]-- > 0) {
            Add(i + minVal); // 6
        }
    }
}
















































































