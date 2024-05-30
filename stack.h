class MyLinkedListStack {
public:
    struct Node { 
        int data;
        Node* next;
    };

    Node* top;
    unsigned long long int N_op;

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
