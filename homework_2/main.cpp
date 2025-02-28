#include <iostream>

//
//  #2: Recursion
//
int arraySum(int arr[], int size) {
    if (size < 1) return 0;
    return arr[size - 1] + arraySum(arr, size - 1);
}

//
//  #3: Arrays
//
bool testArrays(const int arr1[], const int arr2[], int n) {
    if (n <= 0) return false;

    int startIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (arr1[i] == arr2[0]) {
            startIndex = i;
            break;
        }
    }

    if (startIndex == -1) return false;

    for (int i = 0; i < n; ++i) {
        int indexArr1 = (startIndex + i) % n;
        if (arr1[indexArr1] != arr2[i]) return false;
    }

    return true;
}

int main() {

//
//  #1: Implement a Dynamic 2D Array (Matrix) Using Pointers
//

    size_t m, n = 0;

    while (true) {
        std::cout << "\nInput array number of rows: ";
        std::cin >> m;
        if (m > 0) break;
    }

    while (true) {
        std::cout << "\nInput array number of columns: ";
        std::cin >> n;
        if (n > 0) break;
    }


//    Dynamically create a matrix
    int** arr = new int*[m];
    for (int i = 0; i < m; ++i) {
        arr[i] = new int[n];
    }

//    Fill in the values with consecutive numbers
    int c = 0;
    for (int j = 0; j < m; ++j) {
        for (int k = 0; k < n; ++k) {
            arr[j][k] = c++;
        }
    }

//    Print the matrix
    std::cout << std::endl;
    for (int r = 0; r < m; ++r) {
        for (int b = 0; b < n; ++b) {
            std::cout << arr[r][b] << "\t";
        }
        std::cout << "\n";
    }

    for (size_t i = 0; i < m; ++i) delete[] arr[i];
    delete[] arr;

    return EXIT_SUCCESS;
}