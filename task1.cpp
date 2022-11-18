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

    int NumParts = 10;
    int beginMas[NumParts];
    int endMas[NumParts];
    for (int i = 0; i < NumParts; i++)
        beginMas[i] = size / NumParts * i;
    for (int i = 0; i < NumParts - 1; i++)
        endMas[i] = beginMas[i + 1] - 1;

    endMas[NumParts - 1] = size - 1;

    for (int i = 0; i < NumParts; i++) {
        SumMas += findPartSum(mas, beginMas[i], endMas[i]);
    }

    std::cout << SumMas << std::endl;
    return 0;
}
