#include <iostream>

long findPartSum(const int mas[], int begin, int end) {
    long partSum = 0;
    for (int i = begin; i <= end; i++) {
        partSum = partSum + mas[i];
    }
    return partSum;
}

int main() {
    int size = 10000;
    int mas[size];
    long SumMas = 0;

    for (int i = 0; i < size; i++)
        mas[i] = i;

    int NumThread = 10;
    int beginMas[NumThread];
    int endMas[NumThread];
    for (int i = 0; i < NumThread; i++)
        beginMas[i] = size / NumThread * i;
    for (int i = 0; i < NumThread - 1; i++)
        endMas[i] = beginMas[i + 1] - 1;

    endMas[NumThread - 1] = size - 1;

    for (int i = 0; i < NumThread; i++) {
        SumMas += findPartSum(mas, beginMas[i], endMas[i]);
    }

    std::cout << SumMas << std::endl;
    return 0;
}
