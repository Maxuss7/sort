#include "stack.h"
#include <iostream>

using namespace std;

void elems_test(MyLinkedListStack& myStack, int expected[], int size)
{
    vector<int> result = myStack.ToArray();
    
    if (result.size() != size)
    {
        cout << "Fail: Size mismatch" << endl;
        return;
    }

    for (int i = 0; i < result.size(); i++)
    {
        if (expected[i] == result[i])
        {
            printf("Test %d: SUCCES.\n", i+1);
        }
        else 
        {  
            printf("Test %d: FAIL. Expected %d, got %d.\n", i+1, expected[i], result[i]);
        }
    }
}

void delete_test(MyLinkedListStack& myStack, int expected[], int size)
{
    vector<int> result = myStack.ToArray();
    
    if (result.size() != size)
    {
        cout << "Fail: Size mismatch" << endl;
        return;
    }

    for (int i = 0; i < result.size(); i++)
    {
        if (expected[i] == result[i])
        {
            printf("Test %d: SUCCES.\n", i+1);
        }
        else 
        {  
            printf("Test %d: FAIL. Expected %d, got %d.\n", i+1, expected[i], result[i]);
        }
    }
}

void length_test(MyLinkedListStack& myStack, int length)
{
    vector<int> result = myStack.ToArray();
    
    if (result.size() == length)
    {
        printf("SUCCES\n");
    }
    else
    {
        printf("FAIL\n");
    }
}
int main()
{   
    // Добавление элементов
    #ifdef TEST1
    MyLinkedListStack myStack;
    myStack.Add(10);
    myStack.Add(20);
    myStack.Add(30);
    myStack.Add(-1);
    myStack.Add(222222);
    myStack.Add(-9999);
    myStack.Add(0);

    int expected[] = {0, -9999, 222222, -1, 30, 20, 10};

    elems_test(myStack, expected, 7);
    #endif

    // Удаление элементов, корректность последовательности
    // после удаления
    #ifdef TEST2
    MyLinkedListStack myStack;
    myStack.Add(1);
    myStack.Add(5);
    myStack.Add(6);
    myStack.Add(-7);
    myStack.Add(-99);
    myStack.Add(-2);
    

    myStack.Del();
    myStack.Del();

    int expected[] = {-7, 6, 5, 1};

    delete_test(myStack, expected, 4);
    #endif

    // Длина стека
    #ifdef TEST3
    MyLinkedListStack myStack;
    myStack.Add(9);
    myStack.Add(99);
    myStack.Add(999);
    myStack.Add(-123);

    myStack.Del();

    int length = myStack.Length();
    length_test(myStack, length);

    myStack.Del();
    myStack.Del();
    length = myStack.Length();
    length_test(myStack, length);

    myStack.Del();
    length = myStack.Length();
    length_test(myStack, length);

    #endif

    // Просто работа
    #ifdef TEST4
    MyLinkedListStack myStack;

    cout << "---Проверка стека на наличие элементов" << endl;
    myStack.Print();

    cout << "---Добавление 1" << endl;
    myStack.Add(1);
    myStack.Print();

    cout << "---Добавление 4" << endl;
    myStack.Add(4);
    myStack.Print();

    cout << "---Добавление 8" << endl;
    myStack.Add(8);
    myStack.Print();

    cout << "---Верхний элемент = " << myStack.Value() << endl;

    cout << "---Удаление элемента" << endl;
    myStack.Del();
    myStack.Print();
    #endif

    #ifdef TEST5
    Numbers myStack;
    myStack.Add(10);
    myStack.Add(5);
    myStack.Add(7);
    myStack.Add(3);

    cout << "Original stack: ";
    myStack.Print();

    cout << "Get element at position 2: " << myStack.Get(2) << endl;

    cout << "Stack after Get operation: ";
    myStack.Print();

    myStack.Set(1, 20);

    cout << "Stack after Set operation: ";
    myStack.Print();

    myStack.Sort(myStack.Length());

    cout << "Sorted stack: ";
    myStack.Print();

    #endif

}