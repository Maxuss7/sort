#include "stack.h"
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime> 

using namespace std;
using namespace std::chrono;

void FillStackWithRandomNumbers(Numbers& stack, int n) {
    for (int i = 0; i < n; ++i) {
        int randomNumber = (rand() % 20001) - 10000;
        stack.Add(randomNumber);
    }
}

int main()
{   
    setlocale( LC_ALL,"Russian" );
    
    #ifdef TEST1
    srand(time(0)); 

    for (int i = 0, N = 100; N <= 1000; i++, N += 100) {
        Numbers myStack;
        myStack.N_op = 0;
        FillStackWithRandomNumbers(myStack, N);

        auto start = high_resolution_clock::now();

        myStack.Sort(N);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Номер сортировки: " << i + 1 << endl;
        cout << "Количество отсортированных элементов: " << N << endl;
        cout << "Время сортировки (ms): " << duration.count() << endl;
        cout << "Количество операций (N_op): " << myStack.N_op << endl << endl;
    }
    #endif

    #ifdef TEST2
    cout << "Добавление элементов" << endl;
    MyLinkedListStack myStack;
    cout << "До: ";
    myStack.Print();
    cout << "После: ";
    myStack.Add(10);
    myStack.Add(20);
    myStack.Add(30);
    myStack.Add(-1);
    myStack.Add(222222);
    myStack.Add(-9999);
    myStack.Add(0);

    myStack.Print();
    #endif

    #ifdef TEST3
    cout << "Добавление и удаление элементов" << endl;
    MyLinkedListStack myStack;
    myStack.Add(1);
    myStack.Add(5);
    myStack.Add(6);
    myStack.Add(-7);
    myStack.Add(-99);
    myStack.Add(-2);
    cout << "До удаления: ";
    myStack.Print();
    cout << "\n";
    myStack.Del();
    myStack.Del();
    cout << "После удаления: ";
    myStack.Print();
    #endif

    #ifdef TEST4
    MyLinkedListStack myStack;
    myStack.Add(9);
    myStack.Add(99);
    myStack.Add(999);
    myStack.Add(-123);
    
    cout << "Cтек: ";
    myStack.Print();

    cout << "Длина стека " << myStack.Length() << endl;

    myStack.Del();
    myStack.Del();
        cout << "Cтек: ";
    myStack.Print();

    cout << "Длина стека " << myStack.Length() << endl;

    #endif

    #ifdef TEST5
    Numbers myStack;
    myStack.Add(9);
    myStack.Add(99);
    myStack.Add(999);
    myStack.Add(-123);
    myStack.Print();
    cout << "Get(pos=2) = " << myStack.Get(2) << endl;
    cout << "Get(pos=0) = " << myStack.Get(0) << endl;
    cout << "\n";
    cout << "Set(pos=2 делаем 555)" << endl;
    myStack.Set(2, 555);
    myStack.Print();
    cout << "Set(pos=0 666)" << endl;
    myStack.Set(0, 666); 
    myStack.Print();

    #endif

    return 0;
}
