#include "stack.h"
#include <vector>
#include <iostream>
using namespace std;

MyLinkedListStack::MyLinkedListStack() {
    top = nullptr;
    unsigned long long int N_op;
}

MyLinkedListStack::~MyLinkedListStack() {
    while (top != nullptr) {            
        Node* temp = top; N_op++;              
        top = top->next;  N_op++;              
        delete temp;      N_op++;              
        
    }
}

void MyLinkedListStack::Add(int x) { N_op++;   
    Node* newNode = new Node;   N_op++; 
    newNode->data = x;          N_op++;        
    newNode->next = top;        N_op++;        
    top = newNode;              N_op++;        
}

bool MyLinkedListStack::IsEmpty() {
    N_op += 2;
    return top == nullptr;              
}

int MyLinkedListStack::Length() {       
    int count = 0;                      N_op++;
    Node* current = top;                N_op++;
                                        N_op += 2;
    while (current != nullptr) {        N_op += 2;
        count++;                        N_op++;
        current = current->next;        N_op++;
    }
    N_op++;
    return count;                       
}

int MyLinkedListStack::Del() {          
    int val = 0;                        N_op++;
                                        N_op += 4;
    if (!IsEmpty()) {                   
        val = top->data;                N_op++;
        Node* temp = top;               N_op++;
        top = top->next;                N_op++;
        delete temp;                    N_op++;
    } else {
        cout << "Стек пуст" << endl;    N_op++;
    }

    N_op++;
    return val;
}

int MyLinkedListStack::Value() {        
        N_op += 4;    
    if (!IsEmpty()) {                   
        N_op++;
        return top->data;               
    } else {
        N_op++;
        cout << "Стек пуст" << endl;
        N_op++;
        return 0;                       
    }
}

void MyLinkedListStack::Print() {       
                                        N_op += 4;
    if (!IsEmpty()) { 
        Node* current = top;            N_op++;
                                        N_op += 2;    
        while (current != nullptr) {    N_op += 2;
            cout << current->data << " "; N_op++;
            current = current->next;      N_op++;
        }
        cout << endl;                     N_op++;
    } else {
        cout << "Стек пуст" << endl;      N_op++;
    }
}

int Numbers::Get(int pos) {             N_op++;
    MyLinkedListStack tempStack;        N_op++;
    int value = -1;                     N_op++;
                                        N_op += 2;
    for (int i = 0; i <= pos; ++i) {    N_op += 3;
        value = Del();                  
        tempStack.Add(value);           
    }
                                        N_op += 2;
    while (!tempStack.IsEmpty()) {      N_op += 2;
        Add(tempStack.Del());           
    }
                                        N_op++;
    return value;                       
}

void Numbers::Set(int pos, int number) { N_op += 2;
    MyLinkedListStack tempStack;         N_op++;
                                         N_op += 2;
    for (int i = 0; i < pos; ++i) {      N_op += 3;
        tempStack.Add(Del());           
    }

    N_op += 2;
    if (!IsEmpty()) {                   
        Del();                          
        Add(number);                    
    }
    N_op += 2;
    while (!tempStack.IsEmpty()) {      N_op += 2;
        Add(tempStack.Del());           
    }
}

void Numbers::Sort(int n) {             N_op++;
    MyLinkedListStack tempStack;        N_op++;
    
    // Константы для минимального и максимального значений
    const int MIN_VAL = -10000;         N_op++;
    const int MAX_VAL = 10000;          N_op++;

    // Заполняем временный стек данными до сортировки
                                        N_op++;
    for (int i = 0; i < n; ++i) {       N_op += 3;            
        int value = Del();              N_op++;

                                        N_op += 4;
        if (value < MIN_VAL || value > MAX_VAL) {
            cerr << "Out of range value found." << endl; N_op++;
                                                         N_op++;   
            return;                                      
        }
        tempStack.Add(value);                            
    }

    // Создаем временный стек для счетчиков
    // Но придется сделать ноду публичной
    MyLinkedListStack countStack;                       N_op++;

    // Заполняем временный стек счетчиков
                                                        N_op += 2;
    for (int i = MIN_VAL; i <= MAX_VAL; ++i) {          N_op += 3;
        int count = 0;                                  N_op++;
        // Считаем количество элементов с данным значением
        MyLinkedListStack::Node* current = tempStack.top; N_op++;
                                                          N_op += 2;  
        while (current != nullptr) {                      N_op += 2;
                                                          N_op++;  
            if (current->data == i)                
                count++;                                  N_op++;
            current = current->next;                      N_op++;
        }

        countStack.Add(count);                            
    }

    // Добавляем элементы обратно в отсортированном порядке (с конца)
    N_op += 2;
    for (int i = MAX_VAL; i >= MIN_VAL; --i) {              N_op += 3;
        MyLinkedListStack::Node* current = tempStack.top;   N_op++;
                                                            N_op += 2;
        for (int j = 0; j < n; ++j) {                       N_op += 3;
                                                            N_op += 2;
            if (current->data == i) {                       
                Add(i);
                countStack.top->data--;                     N_op++;
                                                            N_op +=2;
                if (countStack.top->data == 0)
                    countStack.Del();
            }
            current = current->next;                        N_op++;
        }
    }
}
