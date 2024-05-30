#ifndef STACK_H
#define STACK_H

#include <vector>
class MyLinkedListStack {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* top;
    unsigned long long int N_op;

public:
    MyLinkedListStack();
    ~MyLinkedListStack();
    void Add(int x);
    bool IsEmpty();
    int Length();
    int Del();
    int Value();
    void Print();
};


class Numbers : public MyLinkedListStack
{
public:
    int Get(int pos);
    void Set(int pos, int number);
    void Sort(int n);
};

#endif 
