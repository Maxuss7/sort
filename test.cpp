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
    srand(time(0)); 

    for (int i = 0, N = 100; N <= 1000; i++, N += 100) {
        Numbers myStack;
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

    return 0;
}
