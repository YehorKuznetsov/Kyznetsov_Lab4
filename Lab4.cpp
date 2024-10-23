#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void printArray(int array[], int size) {

    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
void random (int array[], int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 21;
    }
}
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}
void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, high, pivot + 1);
    }
}
int main() {
    constexpr int size = 20;
    int array[size];
    random(array, size);
    cout << "Array for sorting: " << endl;
    printArray(array, size);
    quickSort(array, 0, size - 1);
    cout << "Array after sorting: " << endl;
    printArray(array, size);
}
