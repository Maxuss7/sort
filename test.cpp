#include "stack.h"
#include <iostream>

using namespace std;

int main()
{   
    #ifdef TEST
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