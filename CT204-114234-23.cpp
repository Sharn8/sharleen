#include<iostream>
#include <vector>

void removeDuplicates(std::vector<int>& arr) {
    if (arr.empty()) return;

    int n = arr.size();
    int uniqueIndex = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[uniqueIndex]) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }

    arr.resize(uniqueIndex + 1);
}

int main() {
    std::vector<int>  sortedArray ={1 2 2 3 4 4 5};

    std::cout << "Original sorted array: ";
    for (int num : sortedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    removeDuplicates(sortedArray);

    std::cout << "Array after removing duplicates: ";
    for (int num : sortedArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}