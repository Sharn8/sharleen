#include <iostream>

void insertAtBeginning(int arr[], int& size, int element) {
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    size++;
}

void insertAtEnd(int arr[], int& size, int element) {
    arr[size] = element;
    size++;
}

void insertAtPosition(int arr[], int& size, int element, int position) {
    if (position < 0 || position > size) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element; 
    size++; 
}

void displayArray(int arr[], int size) {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int MAX_SIZE = 100;
    int array[MAX_SIZE];
    int size = 0;

    insertAtBeginning(array, size, 10);
    insertAtEnd(array, size, 20);
    insertAtPosition(array, size, 15, 1); 

    // Displaying the array
    displayArray(array, size);

    return 0;
}
