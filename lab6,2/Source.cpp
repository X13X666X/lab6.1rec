#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void CreateRandomArray(int* arr, int size, int start, int end, int index = 0) {
    if (index == size) return;
    arr[index] = start + rand() % (end - start + 1);
    CreateRandomArray(arr, size, start, end, index + 1);
}

void PrintArray(int* arr, int size, int index = 0) {
    if (index == 0) cout << "[ ";
    if (index == size) {
        cout << "]" << endl;
        return;
    }
    cout << arr[index];
    if (index < size - 1) cout << ", ";
    PrintArray(arr, size, index + 1);
}

int CountCriteriaElements(int* arr, int size, int index = 0) {
    if (index == size) return 0;
    return (arr[index] > 0 && arr[index] % 2 != 0) + CountCriteriaElements(arr, size, index + 1);
}

int SumCriteriaElements(int* arr, int size, int index = 0) {
    if (index == size) return 0;
    return ((arr[index] > 0 && arr[index] % 2 != 0) ? arr[index] : 0) + SumCriteriaElements(arr, size, index + 1);
}

void ReplaceCriteriaElementsWithZero(int* arr, int size, int index = 0) {
    if (index == size) return;
    if (arr[index] > 0 && arr[index] % 2 != 0) {
        arr[index] = 0;
    }
    ReplaceCriteriaElementsWithZero(arr, size, index + 1);
}

int main() {
    srand((unsigned)time(0));
    const int size = 23;
    const int rangeStart = -25, rangeEnd = 80;
    int arr[size];

    CreateRandomArray(arr, size, rangeStart, rangeEnd);

    cout << "Original array:" << endl;
    PrintArray(arr, size);

    int count = CountCriteriaElements(arr, size);
    int sum = SumCriteriaElements(arr, size);
    ReplaceCriteriaElementsWithZero(arr, size);

    cout << "Count of positive odd elements: " << count << endl;
    cout << "Sum of positive odd elements: " << sum << endl;

    cout << "Modified array:" << endl;
    PrintArray(arr, size);

    return 0;
}